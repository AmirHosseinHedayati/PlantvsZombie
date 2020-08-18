#include "Sun.h"
#include <stdlib.h>
#include "view.h"

Sun::Sun(QGraphicsScene *scene, Score *score, QGraphicsItem *parent ,QTimer *timer)
    : QObject(), QGraphicsPixmapItem(parent) , sunScene {scene}, sunScore{score}
{
    timeIntervals = 0;

    //add to scene
    sunScene->addItem(this);

    int randNum = rand() % 600;
    setPos(randNum,0);

    //set graphic
    setPixmap(QPixmap(":/pictures/sun.png"));

    //connect timer to slot (moveTODown)
    connect(timer , SIGNAL(timeout()) , this , SLOT(moveToDown()));

}

void Sun::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
     sunScore->musicPlayer->play();
     sunScore->increment();
     sunScene->removeItem(this);
     delete this;
}

void Sun::moveToDown()
{
    ++timeIntervals;
    setPos(x() , y()+6);
    if(pos().y() > 750  || timeIntervals == 40){
        sunScene->removeItem(this);
        delete this;
  }
}

