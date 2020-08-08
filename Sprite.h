#ifndef SPRITE_H
#define SPRITE_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include "Zombie.h"
#include <string>
#include <QList>

class Sprite : public QObject , QGraphicsPixmapItem
{
    Q_OBJECT
private:
    QTimer *spriteTimer;
    Zombie *zomb;
    QList <QPixmap> normPicZombieList;
    int currentPic;
public:
    explicit Sprite(QObject *parent = nullptr);
signals:

public slots:
    void switchPic();
};

#endif // SPRITE_H
