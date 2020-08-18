#include "Controller.h"
#include "Button.h"
#include <QTimer>
#include "Shootingplant.h"
#include "Potatoplant.h"
#include "Sunplant.h"
#include <QGraphicsView>

Controller::Controller(QObject *parent) : QObject(parent)
{
    //create scene
    scene = new QGraphicsScene;
    scene->setSceneRect(0,0,960,750);

    //create holder
    holder = new QGraphicsRectItem();
    holder->setRect(0,0,960,750);

    //create and start cTimer
    cTimer = new QTimer();

    //add Score to the scene
    score = new Score(holder);
    score->setPos(20,60);
    scene->addItem(score);

    //test code
    ShootingPlant *shooter = new ShootingPlant(cTimer,holder);
    scene->addItem(shooter);
    shooter->setPos(20,545-118+150+(20));

    //test code
    SunPlant *sunPlanet = new SunPlant(cTimer,score, holder);
    scene->addItem(sunPlanet);
    sunPlanet->setPos(150,545-118+150+(20));

}

Controller::~Controller()
{
    delete holder;
    delete scene;
    delete cTimer;
}

void Controller::spawnZombie( const int& speed , const int& life)
{
    zList.push_back(new Zombie{life,speed,cTimer,holder});
    //add to scene
    scene->addItem(zList.last());
    zList.last()->setPos(960,545-118+150);
}

void Controller::spawnSun()
{
    sunList.push_back(new Sun{scene,score,holder,cTimer});
}

void Controller::spawnPotato(const int &speed)
{
    pList.push_back(new PotatoPlant{speed,cTimer,holder});

    //add to scene
    scene->addItem(pList.last());
    pList.last()->setPos(60,545-118+150);
}

void Controller::spawnCherryBomb()
{
    cbList.push_back(new CherryBomb{cTimer,holder});

    //add to scene
    scene->addItem(cbList.last());
    cbList.last()->setPos(240,545-118-20);
}

