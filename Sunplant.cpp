#include "Sunplant.h"
#include <QTimer>
#include "Sun.h"
#include "Sun2.h"
#include "QDebug"

SunPlant::SunPlant(QTimer *sunReleaseTimer,Score *score, QGraphicsItem *parent) :
    QObject(), Plant(), sunReleaseTimer{sunReleaseTimer}, score{score}
{
    timeIntervals = 0;
    timeInterval = 0;
    currentPic = 0;

    //setGraphic
    setPixmap(QPixmap(":/pictures/s1.png"));

    //connect sunReleaseTimer to ReleaseSun
    connect(sunReleaseTimer,SIGNAL(timeout()), this , SLOT(releaseSun()));

    //add music
    musicPlayer = new QMediaPlayer();
    musicPlayer->setMedia(QUrl("qrc:/music/wakeup.mp3"));

    //connect sunReleaseTimer to slot (switchPic)
    connect(sunReleaseTimer,SIGNAL(timeout()),this , SLOT(switchPic()));
}

void SunPlant::releaseSun()
{
    ++timeIntervals;
    //release sun every 15 seconds
    if(timeIntervals %300 == 0){
    Sun2 *sun = new Sun2(sunReleaseTimer,score);
    sun->setPos(this->x()-100, this->y()-100);
    setPixmap(QPixmap(":/pictures/s1.png"));
    scene()->addItem(sun);
    musicPlayer->play();
    }
}

void SunPlant::switchPic()
{
    ++timeInterval;
    if(timeInterval %290 ==0)
    setPixmap(QPixmap(":/pictures/s2.png"));
}
