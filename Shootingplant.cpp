#include "Shootingplant.h"
#include "Bullet.h"
#include <QGraphicsScene>

ShootingPlant::ShootingPlant(QTimer *shootTimer, QGraphicsItem *parent):
    QObject(), Plant(), shootingTimer{shootTimer}
{
    timeInterval =0;
    timeIntervals = 0;
    currentPic =0;

  //add music
  musicPlayer = new QMediaPlayer();
  musicPlayer->setMedia(QUrl("qrc:/music/throw.mp3"));

  //connect shootTimer to slot(shoot)
  connect(shootTimer, SIGNAL(timeout()), this, SLOT(shoot()));

  //switch between shootiingplant pictures
  connect(shootTimer, SIGNAL(timeout()),this, SLOT(switchPic()));

  //set graphic
  shootingPlantList<<QPixmap(":/pictures/f1.png")<<QPixmap(":/pictures/f2.png")<<
  QPixmap(":/pictures/f3.png");

}

void ShootingPlant::shoot()
{
    //shoot every 400 milliseconds
    timeInterval++;
    if(timeInterval %8 == 0){
        Bullet *bullet = new Bullet(shootingTimer, 24); //24 --> (4*120)/20
        scene()->addItem(bullet);
        bullet->setPos(x()+55,y()-12);

    //play music
        if(musicPlayer->state()== QMediaPlayer::PlayingState){
           musicPlayer->setPosition(0);
        }
        else if(musicPlayer->state()== QMediaPlayer::StoppedState){
           musicPlayer->play();
        }
    }
}

void ShootingPlant::switchPic()
{
    ++timeIntervals;
    if(timeIntervals %2 ==0){
    if(currentPic != shootingPlantList.size()){
    setPixmap(QPixmap(shootingPlantList[currentPic]));
    currentPic++;
    }
    else {
        currentPic =0;
    }
  }
}
