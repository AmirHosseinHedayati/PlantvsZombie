#include "Zombie.h"
#include <QGraphicsScene>
#include <QList>
#include "Plant.h"
#include "Sun.h"
#include "Sun2.h"
#include "Potatoplant.h"
#include "Button.h"

Zombie::Zombie(const int&life, const int& pixPer50MiliSec, QTimer *timer , QGraphicsItem *parent) : QObject(),
QGraphicsPixmapItem(parent), life{life},pixPer50MiliSec {pixPer50MiliSec}
{
currentPic =0;
timeIntervals =0;

//connect timer to slot (switchpic)
connect(timer,SIGNAL(timeout()),this , SLOT(switchPic()));

//connect timer to moveToLeft
connect(timer ,SIGNAL(timeout()), this , SLOT(movetoLeft()));

//add music for zombie
musicPlayer = new QMediaPlayer();
musicPlayer->setMedia(QUrl("qrc:/music/groan.mp3"));
musicPlayer->play();

//add music when you lose
loseMusicPlayer = new QMediaPlayer();
loseMusicPlayer->setMedia(QUrl("qrc:/music/lose.mp3"));

//set graphic
normPicZombieList<<QPixmap(":/pictures/z1.png")<<QPixmap(":/pictures/z2.png")<<QPixmap(":/pictures/z3.png")
                <<QPixmap(":/pictures/z4.png")<<QPixmap(":/pictures/z5.png")<<QPixmap(":/pictures/z6.png")
                   <<QPixmap(":/pictures/z7.png")<<QPixmap(":/pictures/z8.png")<<QPixmap(":/pictures/z9.png")
                   <<QPixmap(":/pictures/z10.png")<<QPixmap(":/pictures/z11.png")<<QPixmap(":/pictures/z12.png")
                     <<QPixmap(":/pictures/z13.png")<<QPixmap(":/pictures/z14.png")<<QPixmap(":/pictures/z15.png");
}

Zombie::~Zombie()
{
    delete musicPlayer;
}

void Zombie::decrementLife()
{
    life--;
    if(life==0){
        scene()->removeItem(this);
        delete this;
    }
}

void Zombie::destroy()
{
    scene()->removeItem(this);
    delete this;
}

void Zombie::movetoLeft()
{

    QList<QGraphicsItem *>collidingObjects = collidingItems();

    for(int i =0 ; i <collidingObjects.size() ; i++){
            Plant *plant =dynamic_cast<Plant*>(collidingObjects[i]);
            PotatoPlant *potato = dynamic_cast<PotatoPlant*>(collidingObjects[i]); 
            if(plant && plant!=potato){
                scene()->removeItem(collidingObjects[i]);
                delete collidingObjects[i];
            }
        }
    setPos(x()-pixPer50MiliSec,y());
    if(x()==0){
      loseMusicPlayer->play();
      exit(1);
    }
}

void Zombie::switchPic()
{
    ++timeIntervals;
    if(timeIntervals %7 ==0){
    if(currentPic != normPicZombieList.size()){
    setPixmap(QPixmap(normPicZombieList[currentPic]));
    currentPic++;
    }
    else {
        currentPic =0;
    }
  }
}



