#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <gamewidget.h>
#include <codewidget.h>
#include <codeblockswidget.h>

class MainWidget : public QWidget
{
    Q_OBJECT
    GameWidget *gameWidget;
    CodeWidget *codeWidget;
    CodeBlocksWidget *codeBlocksWidget;

public:
    explicit MainWidget(QWidget *parent = nullptr);
    void setGame();
    void update(LevelManager *lm);

signals:

public slots:
};

#endif // MAINWIDGET_H
