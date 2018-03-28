#include <QApplication>
#include "gamewidget.h"
#include "mainwidget.h"
#include <QThread>

class Sleeper: public QThread
{
    public:
        static void msleep(int ms)
        {
            QThread::msleep(ms);
        }
};
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    MainWidget* mw = new MainWidget();
    mw->setGame();

    mw->show();



    return a.exec();
}
