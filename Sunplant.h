#ifndef SUNPLANT_H
#define SUNPLANT_H

#include <QObject>
#include <QMediaPlayer>
#include <QList>
#include "Plant.h"
#include "Score.h"

class SunPlant : public QObject, public Plant
{
    Q_OBJECT

public:
    explicit SunPlant(QTimer *sunReleaseTimer,Score *score, QGraphicsItem *parent = nullptr);

private:
    QTimer *sunReleaseTimer;
    QTimer *picTimer;
    QMediaPlayer *musicPlayer;
    Score *score;
    int timeIntervals;
    int timeInterval;
    int currentPic;
    QList <QPixmap> sunPlanetList;

public slots:
    void releaseSun();
    void switchPic();
};

#endif // SUNPLANT_H
