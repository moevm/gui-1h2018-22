#ifndef CODEWIDGET_H
#define CODEWIDGET_H

#include <QWidget>
#include "codeblockbutton.h"
#include "codeblock.h"

class CodeWidget : public QWidget
{
    Q_OBJECT
    CodeBlockButton *cbb[15];
public:
    explicit CodeWidget(QWidget *parent = nullptr);

signals:
    void sendCode(QVector<CodeBlock>*);
    void errorCode();
public slots:
    void highlightBlock(int i);
    void extinguish();
    void setActiveMove();
    void setActiveTurnRight();
    void setActiveTurnLeft();
    void setActiveLoopStart();
    void setActiveLoopEnd();
    void clean();

    void getCode();

};

#endif // CODEWIDGET_H
