#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include <QRect>
#include "levelmanager.h"
#include "levelfield.h"
#include "action.h"

class GameWidget : public QWidget {
    Q_OBJECT

public:
    explicit GameWidget(QWidget *parent = nullptr);
    void showLevel(LevelManager *lm);
    void showNext(LevelManager *lm);
    void showResult(QString res);

signals:

public slots:
};

#endif // GAMEWIDGET_H
