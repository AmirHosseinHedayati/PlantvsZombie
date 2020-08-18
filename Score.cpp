#include "Score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
score = 0;

//set attribute of text of score
setPlainText(QString::number(score));
setDefaultTextColor(Qt::black);
setFont(QFont("Comic Sans MS", 20));


//set sun music
musicPlayer = new QMediaPlayer();
musicPlayer->setMedia(QUrl("qrc:/music/points.mp3"));
musicPlayer->setVolume(50);

}

Score::~Score()
{
    delete musicPlayer;
}

void Score::increment()
{
    score+=25;
    setPlainText(QString::number(score));
}

void Score::decreaseShooitngPlanet()
{
    if(score>=100){
    score-=100;
    setPlainText(QString::number(score));

}
}

int Score::getScore()
{
    return score;
}
