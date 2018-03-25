#include "mainwidget.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
MainWidget::MainWidget(QWidget *parent) : QWidget(parent)
{
    setMinimumSize(QSize(800, 500));
}

void MainWidget::setGame()
{
    setLayout(new QVBoxLayout());
    QHBoxLayout *qhbl = new QHBoxLayout();
    gameWidget = new GameWidget(this);
    codeBlocksWidget = new CodeBlocksWidget(this);
    codeWidget = new CodeWidget(this);
    qhbl->addWidget(gameWidget);
    qhbl->addWidget(codeBlocksWidget);

    layout()->addItem(qhbl);
    qhbl = new QHBoxLayout();
    qhbl->addWidget(codeWidget);
    QPushButton* start = new QPushButton(this);
    start->setMinimumSize(QSize(50, 50));
    start->setMaximumSize(QSize(50, 50));

    qhbl->addWidget(start);
    layout()->addItem(qhbl);

    connect(codeBlocksWidget->getButton(0),SIGNAL(clicked(bool)),codeWidget,SLOT(setActiveMove()));
    connect(codeBlocksWidget->getButton(1),SIGNAL(clicked(bool)),codeWidget,SLOT(setActiveTurnRight()));
    connect(codeBlocksWidget->getButton(2),SIGNAL(clicked(bool)),codeWidget,SLOT(setActiveTurnLeft()));


}

void MainWidget::update(LevelManager *lm)
{
    gameWidget->showLevel(lm);
}

