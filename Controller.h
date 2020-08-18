#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <QObject>
#include <QGraphicsScene>
#include <QTimer>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include "Score.h"
#include "Zombie.h"
#include "Sun.h"
#include "Plant.h"
#include "Potatoplant.h"
#include "Cherrybomb.h"

class Controller : public QObject
{
    Q_OBJECT

    friend class View;
    friend class ShootingPlantIcon;
    friend class Icon;

public:
    explicit Controller(QObject *parent = nullptr);
    ~Controller();
    void spawnZombie(const int& speed , const int& life);
    void spawnSun();
    void spawnPotato(const int& speed );
    void spawnCherryBomb();

private:
    QGraphicsScene *scene;
    QTimer *cTimer;
    QGraphicsRectItem * holder;
    QList <Sun*> sunList;
    QList <Zombie*> zList;
    QList <PotatoPlant*> pList;
    QList <CherryBomb*> cbList;
    Score *score;

};

#endif // CONTROLLER_H
