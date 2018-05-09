#ifndef STARTBUTTON_H
#define STARTBUTTON_H

#include <QPushButton>
#include "startbuttonstates.h"

class StartButton : public QPushButton
{
    Q_OBJECT
    StartButtonState started = START;
public:
    explicit StartButton(QWidget *parent = nullptr);
    void setNext();
    void drawStart();
signals:
    start();
    stop();
    goNext();
public slots:
    void turnState();
};

#endif // STARTBUTTON_H
