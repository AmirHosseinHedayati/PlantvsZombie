#ifndef VIEW_H
#define VIEW_H

#include <QObject>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMouseEvent>
#include <QTimer>
#include <QMediaPlayer>
#include "Controller.h"
#include "Sun.h"
#include "Shootingplant.h"
#include "Zombie.h"

class View : public QGraphicsView
{
    Q_OBJECT

    friend class ShootingPlantIcon;

public:
    explicit View();
    ~View();
      void showMainMenu();
      void showPauseResumeQuit();
      void showQuitTryAgain();

private:
    QTimer *viewTimer;
    int seconds;
    QMediaPlayer *musicPlayer;
    Controller *viewController;
    QGraphicsScene *scene2;

public slots:
    void incrementSec();
    void start();
    void resume();
    void pause();

};

#endif // VIEW_H
