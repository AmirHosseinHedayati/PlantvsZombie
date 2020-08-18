#ifndef SUN_H
#define SUN_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QMouseEvent>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QMediaPlayer>
#include "Score.h"
#include <QTimer>

class Sun : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Sun(QGraphicsScene *scene, Score *score, QGraphicsItem *parent ,
        QTimer *timer);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:
    QTimer *sunDestroyTimer;
    QGraphicsScene *sunScene;
    Score *sunScore;
    int timeIntervals;

public slots:
    void moveToDown();

};

#endif // SUN_H
