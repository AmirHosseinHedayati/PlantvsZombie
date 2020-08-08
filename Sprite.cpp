#include "Sprite.h"

using namespace std;
Sprite::Sprite(QObject *parent) : QObject(parent)
{
    currentPic = 1;
    zomb = new Zombie(6);

    spriteTimer = new QTimer();
    connect(spriteTimer , SIGNAL(timeout()), zomb , SLOT(switchPic()));
    spriteTimer->start(100);

    //intializing the list of pictures of normal zombies(when there is no bullet)
    for(int i = 1 ; i<=5 ; i++){
    normPicZombieList.append(QPixmap(":/pictures/" + QString::number(i) + ".png"));
    }
}

void Sprite::switchPic()
{
    if(currentPic != normPicZombieList.size()){
    zomb->setPixmap(QPixmap(normPicZombieList[currentPic]));
    currentPic++;
    }
    else {
        currentPic =1;
    }


}
