#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QLabel>
#include <gamewidget.h>
#include <codewidget.h>
#include <codeblockswidget.h>
#include <startbutton.h>
#include <levelmanager.h>
#include <action.h>
#include <QtCore/QStack>
#include "loop.h"
#include <QSlider>

//QThread::msleep(ms);

class MainWidget : public QWidget
{
    Q_OBJECT
    GameWidget *gameWidget;
    CodeWidget *codeWidget;
    CodeBlocksWidget *codeBlocksWidget;
    StartButton *startButton;
    QLabel* result;
    LevelManager* levelManager;
    QStack<Loop> loops;
    QVector<CodeBlock> code;
    bool started = false;
    int cursor = 0;
    QSlider* time;
    QPushButton* startGame;
    QPushButton* chooseLevel;
    QPushButton* menu;

public:
    explicit MainWidget(QWidget *parent = nullptr);
    void start();
    void timerEvent(QTimerEvent *event);


signals:
    highlightBlock(int);
    extinguish();

public slots:
    void setGame();
    void setMenu();
    void update();
    void setCode(QVector<CodeBlock>* code);
    void stop();
    void nextLevel();

};

#endif // MAINWIDGET_H
