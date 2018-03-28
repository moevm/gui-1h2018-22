#include "codeblockswidget.h"
#include <QVBoxLayout>
#include <QPushButton>
#include "codeblockbutton.h"
#include "action.h"

CodeBlocksWidget::CodeBlocksWidget(QWidget *parent) : QWidget(parent)
{
    setMaximumWidth(100);
    setMinimumSize(QSize(100, 400));
    for(int i = 0; i < 3; i++){
        cbb[i] = new CodeBlockButton(this);
    }
    setLayout(new QVBoxLayout());
    cbb[0]->setAct(MOVE);
    cbb[1]->setAct(TURN_RIGHT);
    cbb[2]->setAct(TURN_LEFT);
    for(int i = 0; i < 3; i++) {
        connect(cbb[i], SIGNAL(clicked(bool)), this, SLOT(resetSelect()));
        connect(cbb[i], SIGNAL(clicked(bool)), cbb[i], SLOT(on_codeBlockButton_clicked()));

        layout()->addWidget(cbb[i]);
    }
}

CodeBlockButton *CodeBlocksWidget::getButton(int index)
{
    return cbb[index];
}

void CodeBlocksWidget::resetSelect()
{
    for(int i = 0; i < 3; i++){
        cbb[i]->setSelected(false);
        cbb[i]->drawSelect();
    }
}
