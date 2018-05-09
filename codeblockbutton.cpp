#include "codeblockbutton.h"

CodeBlockButton::CodeBlockButton(QWidget *parent) : QPushButton(parent)
{
    setMinimumSize(QSize(50, 50));
    setMaximumSize(QSize(50, 50));
}

void CodeBlockButton::setAct(Action act)
{
    this->act = act;
    drawSelect();
    drawAct();
}

void CodeBlockButton::setChangeAct(Action act)
{
    this->changeAct = act;
}

void CodeBlockButton::setSelected(bool selected)
{
    this->selected = selected;
}

void CodeBlockButton::setIterations(QTextEdit *iterations)
{
    this->iterations = iterations;
}

void CodeBlockButton::drawSelect()
{
    QPalette pal = palette();

    if(selected){
        pal.setColor(QPalette::Button, QColor(Qt::blue));
    } else{
        pal.setColor(QPalette::Button, QColor(Qt::red));
    }
    setAutoFillBackground(true);
    setPalette(pal);
    update();
}

void CodeBlockButton::removeSelect()
{
    setAutoFillBackground(false);
    update();

}

void CodeBlockButton::drawAct()
{
    QPixmap pixmap;
    switch (act) {
    case MOVE:
        pixmap.load("D:/game/GUI/images/move.png");
        break;
    case TURN_RIGHT:
        pixmap.load("D:/game/GUI/images/turn_right.png");
        break;
    case TURN_LEFT:
        pixmap.load("D:/game/GUI/images/turn_left.png");
        break;
    case LOOP_START:
        pixmap.load("D:/game/GUI/images/loop_start.png");
        break;
    case LOOP_END:
        pixmap.load("D:/game/GUI/images/loop_end.png");
        break;
    default:
        break;
    }

    QIcon ButtonIcon(pixmap);
    setIcon(ButtonIcon);
    setIconSize(pixmap.rect().size());
}

bool CodeBlockButton::isSelected()
{
    return selected;
}

Action CodeBlockButton::getAct()
{
    return act;
}

QTextEdit *CodeBlockButton::getIterations()
{
    return iterations;
}

void CodeBlockButton::clean()
{
    if(act == LOOP_END){
        iterations->hide();
        delete iterations;
    }
    act = NOTHING;
    setAutoFillBackground(false);
    drawAct();
}

void CodeBlockButton::on_codeBlockButton_clicked()
{
    selected = true;
    drawSelect();
}

void CodeBlockButton::changeAction()
{
    if(changeAct != NOTHING) {
        if(act == NOTHING){
            act = changeAct;
            if(act == LOOP_END){
                iterations = new QTextEdit(this);
                iterations->setGeometry(15, 10, 20, 25);
                iterations->show();
            }
        } else{
            if(act == LOOP_END){
                iterations->hide();
                delete iterations;
            }
            act = NOTHING;
        }
        drawAct();

    }
}


