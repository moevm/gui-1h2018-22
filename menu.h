#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include <QPushButton>
#include "mainwidget.h"

class Menu : public QWidget
{
    Q_OBJECT
    QPushButton* start;
    QPushButton* chooseLevel;
    MainWidget* mw;
public:
    explicit Menu(MainWidget* mw, QWidget *parent = nullptr);
    QPushButton* getStart();
    QPushButton* getChooseLevel();
signals:

public slots:
    void setMenu();
};

#endif // MENU_H
