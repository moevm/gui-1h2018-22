#ifndef CODEBLOCKSWIDGET_H
#define CODEBLOCKSWIDGET_H

#include <QWidget>
#include "codeblockbutton.h"
#include <QDebug>


class CodeBlocksWidget : public QWidget
{
    Q_OBJECT
    CodeBlockButton *cbb[3];

public:
    explicit CodeBlocksWidget(QWidget *parent = nullptr);

signals:

public slots:
    void resetSelect();
    void log(){
        for(int i = 0; i < 3; i++){
            qDebug() << cbb[i]->isSelected();
        }
        qDebug() << " ";

    }
};

#endif // CODEBLOCKSWIDGET_H
