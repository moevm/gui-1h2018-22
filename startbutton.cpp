#include "startbutton.h"

StartButton::StartButton(QWidget *parent) : QPushButton(parent)
{
    setMinimumSize(QSize(50, 50));
    setMaximumSize(QSize(50, 50));
}

void StartButton::drawStart()
{
    QPixmap pixmap;
    if(started)
        pixmap.load("D:/game/GUI/images/stop.png");
    else
        pixmap.load("D:/game/GUI/images/play.png");
    QIcon ButtonIcon(pixmap);
    setIcon(ButtonIcon);
    setIconSize(pixmap.rect().size());
}

void StartButton::turnState()
{
    started = !started;
    drawStart();
    if(started)
        emit start();
    else
        emit stop();
}


