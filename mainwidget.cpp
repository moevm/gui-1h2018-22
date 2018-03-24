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
    layout()->addWidget(codeWidget);

}

void MainWidget::foo()
{
     gameWidget->foo();
}
