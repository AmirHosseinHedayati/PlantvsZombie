#ifndef CHERRYBOMB_H
#define CHERRYBOMB_H

#include <QObject>
#include <QMediaPlayer>
#include <QList>
#include "Plant.h"

class CherryBomb : public QObject, public Plant
{
    Q_OBJECT
public:
    explicit CherryBomb(QTimer *eTimer, QGraphicsItem *parent = nullptr);
private:
    QTimer *explosionTimer;
    int timeIntervals;
    int timeInterval;
    int currentPic;
    QMediaPlayer *musicPlayer;
    QList <QPixmap> cherryBombList;

signals:

public slots:
    void explosion();
    void switchPic();
    void destroy();
};

#endif // CHERRYBOMB_H
