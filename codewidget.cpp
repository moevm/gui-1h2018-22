#include "codewidget.h"
#include <QHBoxLayout>
#include <QDebug>
CodeWidget::CodeWidget(QWidget *parent) : QWidget(parent)
{
    setMaximumHeight(100);
    setMinimumSize(QSize(800, 100));
    setLayout(new QHBoxLayout());

    for(int i = 0; i < 15; i++){
        cbb[i] = new CodeBlockButton(this);
        layout()->addWidget(cbb[i]);
        connect(cbb[i], SIGNAL(clicked(bool)), cbb[i], SLOT(changeAction()));
    }
}

void CodeWidget::highlightBlock(int i)
{
    cbb[i]->setSelected(true);
    cbb[i]->drawSelect();
    if(i > 0)
        cbb[i-1]->removeSelect();
}

void CodeWidget::extinguish()
{
    for(int i = 0; i < 15; i++)
        cbb[i]->removeSelect();
}

void CodeWidget::setActiveMove()
{
    for(int i = 0; i < 15; i++)
        cbb[i]->setChangeAct(MOVE);
}

void CodeWidget::setActiveTurnRight()
{
    for(int i = 0; i < 15; i++)
        cbb[i]->setChangeAct(TURN_RIGHT);
}

void CodeWidget::setActiveTurnLeft()
{
    for(int i = 0; i < 15; i++)
        cbb[i]->setChangeAct(TURN_LEFT);
}

void CodeWidget::getCode()
{
    QVector<Action>* code = new QVector<Action>(15);
    bool correctCode = cbb[0]->getAct() != NOTHING;
    if(correctCode)
        for(int i =0; i < 15; i++) {
            (*code)[i] = cbb[i]->getAct();
            if((*code)[i] == NOTHING){
               correctCode = false;
            }
            if(!correctCode){
               if((*code)[i] != NOTHING){
                  break;
              }
            }
            if(i == 14){
                correctCode = true;
            }
        }
    if(correctCode)
        emit sendCode(code);
    else
        emit errorCode();
}

