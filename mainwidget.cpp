#include "mainwidget.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QThread>
#include <QTimerEvent>

MainWidget::MainWidget(QWidget *parent) : QWidget(parent)
{
    setMinimumSize(QSize(900, 600));
    startTimer(1000);
}

void MainWidget::setGame()
{
    qDeleteAll(children());

    QVBoxLayout* qvbl = new QVBoxLayout(this);
    QHBoxLayout *qhbl = new QHBoxLayout();
    gameWidget = new GameWidget(this);
    codeBlocksWidget = new CodeBlocksWidget(this);
    codeWidget = new CodeWidget(this);
    qhbl->addWidget(gameWidget);
    qhbl->addWidget(codeBlocksWidget);

    qvbl->addLayout(qhbl);
    qhbl = new QHBoxLayout();
    qhbl->addWidget(codeWidget);
    startButton = new StartButton(this);
    startButton->drawStart();
    qhbl->addWidget(startButton);
    qvbl->addLayout(qhbl);
    qhbl = new QHBoxLayout();
    result = new QLabel(this);
    qhbl->addWidget(result);
    time = new QSlider(Qt::Horizontal,this);
    time->setMaximumWidth(120);
    qhbl->addWidget(time);
    menu = new QPushButton(this);
    menu->setText("Menu");
    menu->setMaximumSize(QSize(90,30));
    qhbl->addWidget(menu);
    qvbl->addLayout(qhbl);
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
    connect(startButton, SIGNAL(goNext()), this, SLOT(nextLevel()));



    connect(codeWidget, SIGNAL(sendCode(QVector<CodeBlock>*)), this, SLOT(setCode(QVector<CodeBlock>*)));
    connect(codeWidget, SIGNAL(errorCode()), startButton, SLOT(turnState()));

    connect(this, SIGNAL(highlightBlock(int)), codeWidget, SLOT(highlightBlock(int)));
    connect(this, SIGNAL(extinguish()), codeWidget, SLOT(extinguish()));

    connect(menu, SIGNAL(clicked(bool)), this, SLOT(setMenu()));


}

void MainWidget::setMenu()
{
    qDeleteAll(children());

    QVBoxLayout* qvbl = new QVBoxLayout(this);
    startGame = new QPushButton("Start", this);
    qvbl->addWidget(startGame);

    connect(startGame, SIGNAL(clicked(bool)), this, SLOT(setGame()));
}

void MainWidget::update()
{
    gameWidget->showLevel(levelManager);
}

void MainWidget::setCode(QVector<CodeBlock> *code)
{
    this->code = QVector<CodeBlock>();
    for(int i = 0; i < code->size(); i++) {
        if((*code)[i].getAction() == NOTHING)
            break;
        this->code.append((*code)[i]);

    }
    start();
}

void MainWidget::stop()
{
    levelManager->setLevel();
    menu->setEnabled(true);
    result->setText("");
    emit extinguish();
    cursor = 0;
    started = false;
    update();
}

void MainWidget::nextLevel()
{
    codeWidget->clean();
    menu->setEnabled(true);
    cursor = 0;
    started = false;
    result->setText("");
    levelManager->setLevel(levelManager->nextLevel());
    update();
}

void MainWidget::start()
{
    started = true;
    menu->setEnabled(false);
}

void MainWidget::timerEvent(QTimerEvent *event)
{   
    if(started){
        if(cursor < code.size()){
        emit extinguish();
        emit highlightBlock(cursor);
        levelManager->updateLevel(code[cursor].getAction());
        if(code[cursor].getAction() == LOOP_START){
            Loop loop;
            if(!loops.isEmpty()){
                loop = loops.top();
                if(loop.getPosition() != cursor){
                    loop.setPosition(cursor);
                    loop.setIndex(0);
                    loops.push(loop);
                }
            }else{
                loop.setPosition(cursor);
                loop.setIndex(0);
                loops.push(loop);
            }

        }
        if(code[cursor].getAction() == LOOP_END){
            Loop loop = loops.pop();
            loop.setIndex(loop.getIndex() + 1);
            if(code[cursor].getIterations() != loop.getIndex()){
                cursor = loop.getPosition();
                loops.push(loop);
            } else{
                cursor++;
            }
        }else{
            cursor++;
            gameWidget->showNext(levelManager);
        }
        if(cursor == code.size()){
            if(levelManager->coinsSize() == 0){
                result->setText("WIN");
                startButton->setNext();
            }else{
                result->setText("LOSE");

            }
        }
    }
    killTimer(event->timerId());
    startTimer(1000 - time->sliderPosition() * 7);
    }
}


