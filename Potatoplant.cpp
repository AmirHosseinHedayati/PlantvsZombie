#include "Potatoplant.h"
#include "Zombie.h"
#include <QGraphicsScene>

PotatoPlant::PotatoPlant(const int& pixPer50MiliSec,QTimer *potatoTimer,QGraphicsItem *parent ):
    QObject(), Plant(), pixPer50MiliSec{pixPer50MiliSec}, potatoTimer{potatoTimer}
{
    currentPic =0;

    //connect timer to slot(switchPic)
    connect(potatoTimer,SIGNAL(timeout()),this , SLOT(switchPic()));

    //connect timer to moveToLeft
    connect(potatoTimer ,SIGNAL(timeout()), this , SLOT(moveToRight()));

    //set graphic
    potatoPicList<<QPixmap(":/pictures/p1.png")<<QPixmap(":/pictures/p2.png")<<
    QPixmap(":/pictures/p3.png")<<QPixmap(":/pictures/p4.png")
                <<QPixmap(":/pictures/p5.png")<<QPixmap(":/pictures/p6.png")<<QPixmap(":/pictures/p7.png")
                <<QPixmap(":/pictures/p8.png")<<QPixmap(":/pictures/p9.png")<<QPixmap(":/pictures/p10.png")
                  <<QPixmap(":/pictures/p11.png")<<QPixmap(":/pictures/p12.png")<<QPixmap(":/pictures/p13.png")
                     <<QPixmap(":/pictures/p14.png")<<QPixmap(":/pictures/p15.png")<<QPixmap(":/pictures/p16.png")
                       <<QPixmap(":/pictures/p17.png")<<QPixmap(":/pictures/p18.png")<<QPixmap(":/pictures/p19.png")
                         <<QPixmap(":/pictures/p20.png")<<QPixmap(":/pictures/p21.png")<<QPixmap(":/pictures/p22.png")
                           <<QPixmap(":/pictures/p23.png")<<QPixmap(":/pictures/p24.png")<<QPixmap(":/pictures/p25.png")
                             <<QPixmap(":/pictures/p26.png")<<QPixmap(":/pictures/p27.png")<<QPixmap(":/pictures/p28.png")
                               <<QPixmap(":/pictures/p29.png")<<QPixmap(":/pictures/p30.png")<<QPixmap(":/pictures/p31.png")
                                 <<QPixmap(":/pictures/p32.png")<<QPixmap(":/pictures/p33.png")<<QPixmap(":/pictures/p34.png")
                                   <<QPixmap(":/pictures/p35.png");

    //add music for rolling of potato
    musicPlayer1 = new QMediaPlayer();
    musicPlayer1->setMedia(QUrl("qrc:/music/bowling.mp3"));
    musicPlayer1->play();

    //add music when potato collide with zombie
    musicPlayer2 = new QMediaPlayer();
    musicPlayer2->setMedia(QUrl("qrc:/music/bowlingimpact.mp3"));
}

void PotatoPlant::moveToRight()
{
    QList<QGraphicsItem*>collidingList = collidingItems();

    //destroy zombie
    for(int i =0 ; i <collidingList.size() ; i++){
        if(typeid (*(collidingList[i]))==typeid (Zombie)){
            dynamic_cast<Zombie*>(collidingList[i])->destroy();
            //musicPlayer2->play();
            //play music
                if(musicPlayer2->state()== QMediaPlayer::PlayingState){
                   musicPlayer2->setPosition(0);
                }
                else if(musicPlayer2->state()== QMediaPlayer::StoppedState){
                   musicPlayer2->play();
                }
         }
    }
    setPos(x()+pixPer50MiliSec,y());
    if(x()>960){
        scene()->removeItem(this);
        delete this;
        return;
     }
}

void PotatoPlant::switchPic()
{
    if(currentPic != potatoPicList.size()){
    setPixmap(QPixmap(potatoPicList[currentPic]));
    currentPic++;
    }
    else {
        currentPic =0;
    }
}
