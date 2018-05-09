#include "startbutton.h"

StartButton::StartButton(QWidget *parent) : QPushButton(parent)
{
    setMinimumSize(QSize(50, 50));
    setMaximumSize(QSize(50, 50));
}

void StartButton::drawStart()
{
    QPixmap pixmap;
    if(started == START)
        pixmap.load("D:/game/GUI/images/play.png");
    else if(started == STOP)
        pixmap.load("D:/game/GUI/images/stop.png");
    else
        pixmap.load("D:/game/GUI/images/next.png");

    QIcon ButtonIcon(pixmap);
    setIcon(ButtonIcon);
    setIconSize(pixmap.rect().size());
}

void StartButton::turnState()
{
    if(started == START){
        started = STOP;
        emit start();
    }else if(started == STOP){
        started = START;
        emit stop();
    }else if(started == NEXT){
        started = START;
        emit goNext();

    }
    drawStart();

}

void StartButton::setNext()
{
    started = NEXT;
    drawStart();
}


