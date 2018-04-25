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

class MainWidget : public QWidget
{
    Q_OBJECT
    GameWidget *gameWidget;
    CodeWidget *codeWidget;
    CodeBlocksWidget *codeBlocksWidget;
    StartButton *startButton;
    QLabel* result;
    LevelManager* levelManager;

    QVector<CodeBlock> code;
    bool started = false;
    int cursor = 0;

public:
    explicit MainWidget(QWidget *parent = nullptr);
    void setGame();
    void start();
    void timerEvent(QTimerEvent *event);


signals:
    highlightBlock(int);
    extinguish();

public slots:
    void update();
    void setCode(QVector<CodeBlock>* code);
    void stop();

};

#endif // MAINWIDGET_H
