#ifndef COIN_H
#define COIN_H
#include <QPoint>

class Coin
{
    QPoint pos;

public:
    Coin();
    Coin(int x,int y);
    void setPos(int x,int y);
    QPoint getPos();
    int getX();
    int getY();
};

#endif // COIN_H
