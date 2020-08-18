#include "view.h"
#include "Button.h"

View::View() : QGraphicsView()
{
    //create viewController
    viewController = new Controller();

    //create scene2
    scene2 = new QGraphicsScene;
    scene2->setSceneRect(0,0,960,750);
    setScene(scene2);

    //set fixed size
    setFixedSize(960,750);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //set background picture
    setBackgroundBrush(QBrush(QImage(":/pictures/back2.png")));

    //setBackgroundBrush(QBrush(QImage(":/pictures/floor1-b.png")));

    //set music background
    musicPlayer = new QMediaPlayer();
    musicPlayer->setMedia(QUrl("qrc:/music/Grasswalk.mp3"));
    musicPlayer->setVolume(50);
    musicPlayer->play();

    //initialize second to zero
    seconds =0;

    //set timer for the view
    viewTimer = new QTimer();
    connect(viewTimer, SIGNAL(timeout()), this, SLOT(incrementSec()));
}

View::~View(){
  delete viewTimer;
  delete musicPlayer;
  delete viewController;
}

void View::incrementSec()
{
    ++seconds;
    if(seconds == 50 || seconds == 54 || seconds == 57 || seconds == 59 || seconds == 60 ){
    viewController->spawnZombie(6,10);
}
    if(seconds %10 == 0){
        viewController->spawnSun();
    }
    if(seconds == 52 || seconds == 56 || seconds == 58 || seconds == 60 || seconds == 62 ){
    viewController->spawnPotato(12);
    }
    if(seconds == 10 || seconds == 20 || seconds == 56){
    viewController->spawnCherryBomb();
    }
}

void View::start()
{
    musicPlayer->stop();
    viewTimer->start(1000);
    viewController->cTimer->start(50);
    setScene(viewController->scene);
    setBackgroundBrush(QBrush(QImage(":/pictures/floor1-b.png")));
}

void View::resume()
{
   viewTimer->start();
   viewController->cTimer->start();
}

void View::pause()
{
    viewTimer->stop();
    viewController->cTimer->stop();
}

void View::showMainMenu()
{
    //create a logo
    QGraphicsPixmapItem *logo = new QGraphicsPixmapItem(QPixmap(":/pictures/introLogo.png"));
    logo->setPos(300,50);
    scene2->addItem(logo);

    //create the play button
    Button *pButton = new Button(QString("PLAY"),viewController->holder);
    pButton->setPos(logo->x()+43, logo->y()+220);
    scene2->addItem(pButton);
    connect(pButton , SIGNAL(clicked()),this,SLOT(start()));


    //create quit button
    Button *qButton = new Button(QString("QUIT"),viewController->holder);
    qButton->setPos(logo->x()+43, pButton->y()+110);
    scene2->addItem(qButton);
    connect(qButton , SIGNAL(clicked()),this,SLOT(close()));
}

void View::showPauseResumeQuit()
{
    //create resume button
    Button *rButton = new Button(QString("RESUME      "),viewController->holder);
    rButton->setRect(0,0,250,80);
    rButton->setPos(700, 5);
    viewController->scene->addItem(rButton);
    connect(rButton , SIGNAL(clicked()),this,SLOT(resume()));

    //create pause button
    Button *pButton = new Button(QString("PAUSE  "),viewController->holder);
    pButton->setRect(0,0,250,80);
    pButton->setPos(700, 90);
    viewController->scene->addItem(pButton);
    connect(pButton , SIGNAL(clicked()),this,SLOT(pause()));

    //create quit button
    Button *qButton = new Button(QString("QUIT"),viewController->holder);
    qButton->setRect(0,0,250,80);
    qButton->setPos(700, 175);
    viewController->scene->addItem(qButton);
    connect(qButton , SIGNAL(clicked()),this,SLOT(close()));
}







