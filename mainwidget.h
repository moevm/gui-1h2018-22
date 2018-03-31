#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <gamewidget.h>
#include <codewidget.h>
#include <codeblockswidget.h>
#include <startbutton.h>
#include <levelmanager.h>
#include <action.h>

class MainWidget : public QWidget
{
    Q_OBJECT
    GameWidget *gameWidget;
    CodeWidget *codeWidget;
    CodeBlocksWidget *codeBlocksWidget;
    StartButton *startButton;

    LevelManager* levelManager;

    QVector<Action> code;
    bool started = false;
    int count = 0;

public:
    explicit MainWidget(QWidget *parent = nullptr);
    void setGame();
    void start();
    void timerEvent(QTimerEvent *event);


signals:
    highlightBlock(int);

public slots:
    void update();
    void setCode(QVector<Action>* code);

};

#endif // MAINWIDGET_H
