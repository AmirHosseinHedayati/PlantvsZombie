#ifndef SCORE_H
#define SCORE_H

#include<QGraphicsTextItem>
#include<QMediaPlayer>

class Score : public QGraphicsTextItem
{
    friend class Sun;
    friend class Sun2;
public:
    explicit Score(QGraphicsItem *parent);
    ~Score();
    void increment();
    void decreaseShooitngPlanet();
    int getScore();

private:
     int score;
     QMediaPlayer *musicPlayer;
};

#endif // SCORE_H
