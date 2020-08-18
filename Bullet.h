#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QMediaPlayer>

class Bullet : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    explicit Bullet(QTimer *bullTimer, const int &sp, QGraphicsItem *parent = nullptr);

private:
    int speed;
    QMediaPlayer *musicPlayer;

public slots:
    void moveToRight();
};

#endif // BULLET_H
