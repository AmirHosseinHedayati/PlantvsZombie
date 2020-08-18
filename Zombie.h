#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QList>
#include <QMediaPlayer>
#include <QGraphicsScene>
class Zombie : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Zombie(const int&life, const int& pixPer50MiliSec, QTimer *timer ,  QGraphicsItem *parent);
    ~Zombie();
    void decrementLife();
    void destroy();

private:
    QTimer *picTimer;
    int life;
    int pixPer50MiliSec;
    QList <QPixmap> normPicZombieList;
    int currentPic;
    QMediaPlayer *musicPlayer;
    QMediaPlayer *loseMusicPlayer;
    int timeIntervals;


public slots:
    void movetoLeft();
    void switchPic();
};

#endif // ZOMBIE_H
