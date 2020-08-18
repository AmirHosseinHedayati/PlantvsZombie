#include "Cherrybomb.h"
#include <QGraphicsScene>
#include <QTimer>
#include "Zombie.h"

CherryBomb::CherryBomb(QTimer *eTimer, QGraphicsItem *parent) :
    QObject(), Plant(), explosionTimer{eTimer}
{
 timeIntervals = 0;
 timeInterval = 0;
 currentPic = 0;

 //set graphic
 cherryBombList<<QPixmap(":/pictures/cherrybomb0.png")<<QPixmap(":/pictures/cherrybomb1.png")<<
 QPixmap(":/pictures/cherrybomb2.png")<<QPixmap(":/pictures/cherrybomb3.png")<<
                    QPixmap(":/pictures/cherrybomb4.png");

 //connect explosionTimer to slot(explosion)
 connect(explosionTimer, SIGNAL(timeout()),this, SLOT(explosion()));

 //switch pictures of cherrybomb
 connect(explosionTimer, SIGNAL(timeout()), this, SLOT(switchPic()));


 //add music for explosion
 musicPlayer = new QMediaPlayer();
 musicPlayer->setMedia(QUrl("qrc:/music/cherrybomb.mp3"));
}

void CherryBomb::explosion()
{
    QList<QGraphicsItem*>collidingList = collidingItems();
    //explode after 2 seconds
    timeIntervals++;
    if(timeIntervals % 40== 0){
        for(int i =0 ; i <collidingList.size() ; i++){
            if(typeid (*(collidingList[i]))==typeid (Zombie)){
                dynamic_cast<Zombie*>(collidingList[i])->destroy();
             }
        }
        scene()->removeItem(this);
        delete this;

        //play music
        if(musicPlayer->state()== QMediaPlayer::PlayingState){
           musicPlayer->setPosition(0);
        }
        else if(musicPlayer->state()== QMediaPlayer::StoppedState){
           musicPlayer->play();
      }
    }
}

void CherryBomb::switchPic()
{
    ++timeInterval;
    if(timeInterval %7 ==0){
    if(currentPic != cherryBombList.size()){
    setPixmap(QPixmap(cherryBombList[currentPic]));
    currentPic++;
    }
    else {
        currentPic =0;
    }
  }
}

void CherryBomb::destroy()
{
    scene()->removeItem(this);
    delete this;
}

