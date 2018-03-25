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

public slots:
    void setActiveMove();
    void setActiveTurnRight();
    void setActiveTurnLeft();

};

#endif // CODEWIDGET_H
