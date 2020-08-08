#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QList>
class Zombie : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Zombie(const int& pixPer50MiliSec);
private:
    QTimer *zTimer;
    QTimer *picTimer;
    int life;
    int pixPer50MiliSec;
    QList <QPixmap> normPicZombieList;
    int currentPic;

public slots:
    void movetoLeft();
    void switchPic();
};

#endif // ZOMBIE_H
