#include "mainwindow.h"
#include <QApplication>
#include "gamewidget.h"
#include "mainwidget.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    MainWidget* mw = new MainWidget();
    mw->setGame();
    mw->foo();
    mw->show();
    return a.exec();
}
