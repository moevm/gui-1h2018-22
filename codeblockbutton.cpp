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

void CodeBlockButton::drawSelect()
{
    QPalette pal = palette();

    if(selected){
        pal.setColor(QPalette::Button, QColor(Qt::green));
    } else{
        pal.setColor(QPalette::Button, QColor(Qt::red));
    }
    setAutoFillBackground(true);
    setPalette(pal);
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

void CodeBlockButton::on_codeBlockButton_clicked()
{
    selected = true;
    drawSelect();
}

void CodeBlockButton::changeAction()
{
    if(changeAct != NOTHING) {
        act = act == NOTHING ? changeAct : NOTHING;
        drawAct();

    }
}


