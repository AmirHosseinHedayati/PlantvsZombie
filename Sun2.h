#ifndef SUN2_H
#define SUN2_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QTimer>
#include "Score.h"

class Sun2: public QObject , public QGraphicsPixmapItem
{
     Q_OBJECT

public:
    Sun2(QTimer *timer, Score *score,QGraphicsItem *parent= nullptr);

private:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    Score *sun2Score;
    int timeIntervals;

public slots:
    void destroy();
};

#endif // SUN2_H
