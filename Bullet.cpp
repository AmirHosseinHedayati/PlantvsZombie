#include "Bullet.h"
#include <QGraphicsScene>
#include <QList>
#include "Zombie.h"

Bullet::Bullet(QTimer *bullTimer, const int &sp, QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent), speed{sp}
{

//set graphic
setPixmap(QPixmap(":/pictures/bullet.png"));

//connect to SLOT (moveToRight)
connect(bullTimer,SIGNAL(timeout()),this,SLOT(moveToRight()));

//set music for cooliding bullet with zombie
musicPlayer = new QMediaPlayer();
musicPlayer->setMedia(QUrl("qrc:/music/splat.mp3"));
}

void Bullet::moveToRight()
{
    QList<QGraphicsItem*>collidingList = collidingItems();

    //decrement from zombie lives
    for(int i =0 ; i <collidingList.size() ; i++){
        if(typeid (*(collidingList[i]))==typeid (Zombie)){
            dynamic_cast<Zombie*>(collidingList[i])->decrementLife();
            musicPlayer->play();
            scene()->removeItem(this);
            delete this;
            return;
        }
    }
    setPos(x()+speed , y());
    if(x()>960){
        scene()->removeItem(this);
        delete this;
    }
}
