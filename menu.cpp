#include "menu.h"
#include <QVBoxLayout>

Menu::Menu(MainWidget* mw, QWidget *parent) : QWidget(parent), mw(mw)
{

}

QPushButton *Menu::getStart()
{
    return start;
}

QPushButton *Menu::getChooseLevel()
{
    return chooseLevel;
}

void Menu::setMenu()
{
    setLayout(new QVBoxLayout());
    start = new QPushButton("Start",this);
    layout()->addWidget(start);
    chooseLevel = new QPushButton("Choose level", this);
    layout()->addWidget(chooseLevel);
    connect(start, SIGNAL(clicked(bool)), mw, SLOT(setGame()));
}
