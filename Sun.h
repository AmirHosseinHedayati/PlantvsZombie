#ifndef SUN_H
#define SUN_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include "Score.h"
class Sun : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Sun();
    QTimer *sunTimer;
    QTimer *sunDestroyTimer;
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    Score *score;
public slots:
    void moveToDown();
    void destroySun();

};

#endif // SUN_H
