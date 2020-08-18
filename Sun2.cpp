#include "Sun2.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

Sun2::Sun2( QTimer *timer,Score *score,QGraphicsItem *parent): QObject( ), QGraphicsPixmapItem(parent), sun2Score{score}
{
    timeIntervals =0;

    //set graphic
     setPixmap(QPixmap(":/pictures/sun.png"));

     //connect timer to slot (destroy)
     connect(timer , SIGNAL(timeout()),this,SLOT(destroy()));
}

void Sun2::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    sun2Score->musicPlayer->play();
    sun2Score->increment();
    scene()->removeItem(this);
    delete this;
}

void Sun2::destroy()
{
    ++timeIntervals;
    if(timeIntervals %40 ==0 ){
    scene()->removeItem(this);
    delete this;
    }
}

