#ifndef CODEBLOCKSWIDGET_H
#define CODEBLOCKSWIDGET_H

#include <QWidget>
#include "codeblockbutton.h"
#include <QDebug>


class CodeBlocksWidget : public QWidget
{
    Q_OBJECT
    CodeBlockButton *cbb[5];

public:
    explicit CodeBlocksWidget(QWidget *parent = nullptr);

    CodeBlockButton* getButton(int index);

signals:

public slots:
    void resetSelect();
};

#endif // CODEBLOCKSWIDGET_H
