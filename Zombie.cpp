#include "Zombie.h"

Zombie::Zombie(const int& pixPer50MiliSec) : QObject(), QGraphicsPixmapItem()
{

currentPic =0;

this->pixPer50MiliSec = pixPer50MiliSec;
//setPixmap(QPixmap(":/pictures/1.png"));

picTimer = new QTimer();
connect(picTimer,SIGNAL(timeout()),this , SLOT(switchPic()));
picTimer->start(300);

zTimer = new QTimer();
connect(zTimer ,SIGNAL(timeout()), this , SLOT(movetoLeft()));
zTimer->start(50);


normPicZombieList<<QPixmap(":/pictures/1.png")<<QPixmap(":/pictures/2.png")<<
QPixmap(":/pictures/3.png")<<QPixmap(":/pictures/4.png")<<
QPixmap(":/pictures/5.png");
}

void Zombie::movetoLeft()
{
    setPos(x()-pixPer50MiliSec,y());

    if(x()==0){

    }
}

void Zombie::switchPic()
{
    if(currentPic != normPicZombieList.size()){
    setPixmap(QPixmap(normPicZombieList[currentPic]));
    currentPic++;
    }
    else {
        currentPic =0;
}
}
