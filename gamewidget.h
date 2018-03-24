#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include <QRect>
#include "levelmanager.h"
#include "levelfield.h"

class GameWidget : public QWidget
{
    Q_OBJECT
    QRect last_rect;
    QVector<QVector<bool>> level;
public:
    explicit GameWidget(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void timerEvent(QTimerEvent *event);
    void createLevel(QVector<QVector<bool>> level);
    void setLevel(QVector<QVector<bool>> level);
    void foo();
signals:

public slots:
};

#endif // GAMEWIDGET_H
