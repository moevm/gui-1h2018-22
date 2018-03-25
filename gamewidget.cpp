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
    //this->setPalette(Pal);

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

void GameWidget::showLevel(LevelManager *lm)
{

    QVector<QVector<FieldState>> level = lm->getCurrentLevel();
    //if(!level.isEmpty()){
    QGridLayout* gl = new QGridLayout(this);
    //setLayout(gl);
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 6; j++){
            LevelField* lf = new LevelField(this);
            qDebug() << level[i][j];
            lf->setField(level[i][j]);
            gl->addWidget(lf,i, j);
        }
    }
    //}


}


