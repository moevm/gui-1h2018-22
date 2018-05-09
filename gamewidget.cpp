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
    setMinimumSize(QSize(600, 400));
}

void GameWidget::showLevel(LevelManager *lm)
{
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
}

void GameWidget::showNext(LevelManager *lm)
{
    if(lm->getPlayer().getPos() != lm->getPrevPlayersPos()){
        ((LevelField*) layout()->itemAt(lm->getPrevPlayersPos().x() *lm->getCurrentLevel().at(0).size() + lm->getPrevPlayersPos().y() )->widget())->removeCoin();
        ((LevelField*) layout()->itemAt(lm->getPrevPlayersPos().x() *lm->getCurrentLevel().at(0).size() + lm->getPrevPlayersPos().y() )->widget())->setField(CELL);
    }
    ((LevelField*) layout()->itemAt(lm->getPlayer().getPos().x() * lm->getCurrentLevel().at(0).size() + lm->getPlayer().getPos().y())->widget())->setField(lm->getPlayer().getTurn());

}





