#ifndef STARTBUTTON_H
#define STARTBUTTON_H

#include <QPushButton>


class StartButton : public QPushButton
{
    Q_OBJECT
    bool started = false;
public:
    explicit StartButton(QWidget *parent = nullptr);

    void drawStart();
signals:
    start();
    stop();
public slots:
    void turnState();
};

#endif // STARTBUTTON_H
