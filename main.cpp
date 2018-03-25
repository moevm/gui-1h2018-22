#include <QApplication>
#include "gamewidget.h"
#include "mainwidget.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    MainWidget* mw = new MainWidget();
    mw->setGame();
    LevelManager* lm = new LevelManager();
    lm->setLevel(0);
    mw->update(lm);
    mw->show();


    return a.exec();
}
