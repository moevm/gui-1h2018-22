#include "levelfield.h"
#include <QPainter>
#include <QRect>
#include <QPaintEvent>

LevelField::LevelField(QWidget *parent) : QWidget(parent)
{

}

void LevelField::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    //QRect rect;
    p.setPen(QColor(100,100,100));
    p.drawRoundedRect(event->rect(), 4, 4);
}
