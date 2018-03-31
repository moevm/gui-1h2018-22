#include "coin.h"

Coin::Coin()
{

}

Coin::Coin(int x, int y)
{
    pos = QPoint(x, y);
}

void Coin::setPos(int x, int y)
{
    pos = QPoint(x, y);
}

QPoint Coin::getPos()
{
    return pos;
}

int Coin::getX()
{
    return pos.x();
}

int Coin::getY()
{
    return pos.y();
}
