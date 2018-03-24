#include "gamewidget.h"
#include <QPainter>
#include <QPaintEvent>
#include<QPoint>
#include <QDebug>
#include <QGridLayout>
#include <QPushButton>
#include <QHBoxLayout>

GameWidget::GameWidget(QWidget *parent) : QWidget(parent)
{
    //qDebug() << this->width();
    //qDebug() << this->height();
    //last_rect = QRect(100, 100, 10, 10);
    QPalette Pal(palette());

    // устанавливаем цвет фона
    Pal.setColor(QPalette::Background, QColor(0,0,255));
    this->setAutoFillBackground(true);
    this->setPalette(Pal);

    setMinimumSize(QSize(600, 400));

    //startTimer(30);
}

void GameWidget::paintEvent(QPaintEvent *event)
{
    //qDebug() << this->width();
    //qDebug() << this->height();


   //QPainter p(this);
   //p.setPen(Qt::red);
   //p.setBrush(Qt::red);
   //p.drawEllipse(last_rect);
}

void GameWidget::timerEvent(QTimerEvent *event){
    //emit update();
}

void GameWidget::createLevel(QVector<QVector<bool>> level)
{


    this->level = level;
    QWidget *w = new QWidget(this);
    //if(!level.isEmpty()){
    QGridLayout* gl = new QGridLayout(w);
    //setLayout(gl);
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            gl->addWidget(new QPushButton(this),i, j);
            qDebug() << "Hi";
        }
    }
    //}


}

void GameWidget::setLevel(QVector<QVector<bool> > level)
{
    this->level = level;

}

void GameWidget::foo()
{
}
