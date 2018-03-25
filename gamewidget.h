#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include <QRect>
#include "levelmanager.h"
#include "levelfield.h"

class GameWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GameWidget(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void timerEvent(QTimerEvent *event);
    void showLevel(LevelManager *lm);

signals:

public slots:
};

#endif // GAMEWIDGET_H
