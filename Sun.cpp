#include "Sun.h"
#include <stdlib.h>
#include "View.h"

extern View *view;
Sun::Sun() : QObject(), QGraphicsPixmapItem()
{
    int randNum = rand() % 600;

    setPos(randNum,0);
    setPixmap(QPixmap(":/pictures/sun.png"));

sunTimer = new QTimer();
connect(sunTimer , SIGNAL(timeout()) , this , SLOT(moveToDown()));
sunTimer->start(50);

sunDestroyTimer = new QTimer();
connect(sunDestroyTimer , SIGNAL(timeout()), this , SLOT(destroySun()));
sunDestroyTimer->start(5000);

score = new Score();
}

void Sun::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
   if(event->button()==Qt::LeftButton){
       view->score->increment();
       delete this;
       return;

   }
}

void Sun::moveToDown()
{
    setPos(x() , y()+10);
    if(pos().y() == 500 ){
        sunTimer->stop();
    }

    if(pos().y() >=750){
        delete this;
        qDebug()<<"sun deleted";
    }
}

void Sun::destroySun()
{
    delete this;
}
