#include "mainwidget.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>

MainWidget::MainWidget(QWidget *parent) : QWidget(parent)
{
    setMinimumSize(QSize(800, 500));

    startTimer(1000);
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
    startButton = new StartButton(this);
    startButton->drawStart();
    qhbl->addWidget(startButton);
    layout()->addItem(qhbl);
    qhbl = new QHBoxLayout();
    result = new QLabel(this);
    qhbl->addWidget(result);
    layout()->addItem(qhbl);
    levelManager = new LevelManager();
    levelManager->setLevel(0);
    update();

    connect(codeBlocksWidget->getButton(0),SIGNAL(clicked(bool)),codeWidget,SLOT(setActiveMove()));
    connect(codeBlocksWidget->getButton(1),SIGNAL(clicked(bool)),codeWidget,SLOT(setActiveTurnRight()));
    connect(codeBlocksWidget->getButton(2),SIGNAL(clicked(bool)),codeWidget,SLOT(setActiveTurnLeft()));
    connect(codeBlocksWidget->getButton(3),SIGNAL(clicked(bool)),codeWidget,SLOT(setActiveLoopStart()));
    connect(codeBlocksWidget->getButton(4),SIGNAL(clicked(bool)),codeWidget,SLOT(setActiveLoopEnd()));


    connect(startButton, SIGNAL(clicked(bool)), startButton, SLOT(turnState()));
    connect(startButton, SIGNAL(start()), codeWidget, SLOT(getCode()));
    connect(startButton, SIGNAL(stop()), this, SLOT(stop()));


    connect(codeWidget, SIGNAL(sendCode(QVector<Action>*)), this, SLOT(setCode(QVector<Action>*)));
    connect(codeWidget, SIGNAL(errorCode()), startButton, SLOT(turnState()));

    connect(this, SIGNAL(highlightBlock(int)), codeWidget, SLOT(highlightBlock(int)));
    connect(this, SIGNAL(extinguish()), codeWidget, SLOT(extinguish()));


}

void MainWidget::update()
{
    gameWidget->showLevel(levelManager);
}

void MainWidget::setCode(QVector<Action> *code)
{
    this->code = QVector<Action>();
    for(int i = 0; i < code->size(); i++) {
        if((*code)[i] == NOTHING)
            break;
        qDebug() << (*code)[i];
        this->code.append((*code)[i]);

    }
    start();
}

void MainWidget::stop()
{
    levelManager->setLevel(0);
    result->setText("");
    emit extinguish();
    cursor = 0;
    started = false;
    update();
}

void MainWidget::start()
{
    started = true;
}

void MainWidget::timerEvent(QTimerEvent *event)
{
    if(started && cursor < code.size()){
        emit highlightBlock(cursor);
        levelManager->updateLevel(code[cursor++]);
        if(cursor == code.size()){
              QString qs;
              qs = levelManager->coinsSize() == 0 ? "WIN" : "LOSE";

              result->setText(qs);

        } else {

        }
        update();

    }
}


