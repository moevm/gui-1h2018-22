#include "gamewidget.h"
#include <QPainter>
#include <QPaintEvent>
#include<QPoint>
#include <QDebug>
#include <QGridLayout>
#include <QPushButton>
#include <QHBoxLayout>
#include <QLabel>

GameWidget::GameWidget(QWidget *parent) : QWidget(parent)
{
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

}

void GameWidget::timerEvent(QTimerEvent *event){
}

void GameWidget::showLevel(LevelManager *lm)
{
    //qDebug() << "StartShow";
    qDeleteAll(children());
    QVector<QVector<FieldState>> level = lm->getCurrentLevel();
    QGridLayout* gl = new QGridLayout(this);
    for(int i = 0; i < level.size(); i++){
        for(int j = 0; j < level[0].size(); j++){
            LevelField* lf = new LevelField(this);
            lf->setField(level[i][j]);
            if(lm->hasCoin(i, j)) {
                lf->putCoin();
            }
            gl->addWidget(lf,i, j);

        }
    }
    //}


}





