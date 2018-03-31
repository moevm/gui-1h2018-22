#include "levelfield.h"
#include <QPainter>
#include <QRect>
#include <QPaintEvent>
#include <QDebug>
#include <QLabel>
#include <QGraphicsView>
#include <QPixmap>
#include <QPen>

LevelField::LevelField(QWidget *parent) : QWidget(parent)
{


    //setMinimumSize(QSize(100, 100));
}



void LevelField::setField(FieldState fs)
{
    this->fs = fs;    
}

void LevelField::putCoin()
{
    hasCoin = true;
}

void LevelField::paintEvent(QPaintEvent *event)
{
    QPalette Pal(palette());

    if(fs == CELL) {
        Pal.setColor(QPalette::Background, QColor(100,100,255));
        if(hasCoin){
            QPixmap pixmap;
            QPainter painter(this);
            pixmap.load("D:/game/GUI/images/coin.png");
            painter.drawPixmap( QPoint((width() - pixmap.width())/2,(height()-pixmap.height())/2), pixmap );

        }
    } else if(fs == WALL) {
        Pal.setColor(QPalette::Background, QColor(150,150,150));
    } else {
        Pal.setColor(QPalette::Background, QColor(255,255,50));

        QPainter p(this);
        QPen pen;
        pen.setWidth(5);
        pen.setJoinStyle(Qt::RoundJoin);
        p.setPen(pen);
        switch (fs) {
        case PLAYER_RIGHT:
        {
            p.drawLine(width()* 0.9, height() * 0.5, width() * 0.5, height() * 0.3);
            p.drawLine(width()* 0.9, height() * 0.5, width() * 0.5, height() * 0.7);
            break;
        }
        case PLAYER_LEFT:
        {
            p.drawLine(width()* 0.1, height() * 0.5, width() * 0.5, height() * 0.3);
            p.drawLine(width()* 0.1, height() * 0.5, width() * 0.5, height() * 0.7);
            break;
        }
        case PLAYER_UP:
        {
            p.drawLine(width()* 0.5, height() * 0.9, width() * 0.3, height() * 0.5);
            p.drawLine(width()* 0.5, height() * 0.9, width() * 0.7, height() * 0.5);
            break;
        }
        case PLAYER_DOWN:
        {
            p.drawLine(width()* 0.5, height() * 0.1, width() * 0.3, height() * 0.5);
            p.drawLine(width()* 0.5, height() * 0.1, width() * 0.7, height() * 0.5);
            break;
        }
        default:
            break;
        }

    }
    this->setAutoFillBackground(true);
    this->setPalette(Pal);
    update();
}
