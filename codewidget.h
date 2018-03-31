#ifndef CODEWIDGET_H
#define CODEWIDGET_H

#include <QWidget>
#include "codeblockbutton.h"

class CodeWidget : public QWidget
{
    Q_OBJECT
    CodeBlockButton *cbb[15];
public:
    explicit CodeWidget(QWidget *parent = nullptr);

signals:
    void sendCode(QVector<Action>*);
    void errorCode();
public slots:
    void highlightBlock(int i);
    void setActiveMove();
    void setActiveTurnRight();
    void setActiveTurnLeft();
    void getCode();

};

#endif // CODEWIDGET_H
