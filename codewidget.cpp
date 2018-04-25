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

void CodeWidget::setActiveLoopStart()
{
    for(int i = 0; i < 15; i++)
        cbb[i]->setChangeAct(LOOP_START);
}

void CodeWidget::setActiveLoopEnd()
{
    for(int i = 0; i < 15; i++)
        cbb[i]->setChangeAct(LOOP_END);
}

void CodeWidget::getCode()
{
    QVector<CodeBlock>* code = new QVector<CodeBlock>(15);
    bool correctCode = cbb[0]->getAct() != NOTHING;
    int loops = 0;
    if(correctCode)
        for(int i =0; i < 15; i++) {
            (*code)[i].setAction(cbb[i]->getAct());
            if((*code)[i].getAction() == NOTHING){
               correctCode = false;
            }
            if((*code)[i].getAction() == LOOP_START){
                loops++;
            }
            if((*code)[i].getAction() == LOOP_END){
                loops--;
                int iter = cbb[i]->getIterations()->toPlainText().toInt();

                if(loops < 0 || iter <= 0){
                    correctCode = false;
                    break;
                }
            }
            if(!correctCode){
               if((*code)[i].getAction() != NOTHING){
                  break;
              }
            }
            if(i == 14){
                correctCode = loops == 0;
            }
        }
    if(correctCode)
        emit sendCode(code);
    else
        emit errorCode();
}

