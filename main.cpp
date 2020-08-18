#include <QApplication>
#include "view.h"
#include <cstdlib>
#include <ctime>
#include <Zombie.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    srand(time(0));
    View *view = new View();
    view->showMainMenu();
    view->show();
    view->showPauseResumeQuit();
    return a.exec();
}
