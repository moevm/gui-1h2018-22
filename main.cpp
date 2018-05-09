#include <QApplication>
#include "gamewidget.h"
#include "mainwidget.h"
#include <QThread>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    MainWidget* mw = new MainWidget();
    mw->setGame();

    mw->show();



    return a.exec();
}
