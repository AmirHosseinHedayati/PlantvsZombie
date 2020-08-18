#ifndef SHOOTINGPLANT_H
#define SHOOTINGPLANT_H


#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include "Plant.h"
#include <QMediaPlayer>
#include <QTimer>
#include <QList>

class ShootingPlant : public QObject, public Plant
{
    Q_OBJECT
public:
    explicit ShootingPlant(QTimer *shootTimer, QGraphicsItem *parent = nullptr);

private:
    int timeInterval;
    int timeIntervals;
    int currentPic;
    QMediaPlayer *musicPlayer;
    QTimer *shootingTimer;
    QList <QPixmap> shootingPlantList;

public slots:
    void shoot();
    void switchPic();
};

#endif // SHOOTINGPLANET_H
