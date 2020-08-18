#ifndef POTATOPLANT_H
#define POTATOPLANT_H
#include "Plant.h"
#include <QObject>
#include <QTimer>
#include <QList>
#include <QMediaPlayer>

class PotatoPlant : public QObject , public Plant
{
    Q_OBJECT

public:
    explicit PotatoPlant(const int& pixPer50MiliSec,QTimer *potatoTimer,QGraphicsItem *parent = nullptr);

private:
    QTimer *potatoTimer;
    QList <QPixmap> potatoPicList;
    int pixPer50MiliSec;
    int currentPic;
    QMediaPlayer *musicPlayer1;
    QMediaPlayer *musicPlayer2;

public slots:
    void moveToRight();
    void switchPic();
};

#endif // POTATOPLANT_H
