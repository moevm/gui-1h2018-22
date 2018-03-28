#ifndef PLAYER_H
#define PLAYER_H
#include <QPoint>
#include <fieldstate.h>

class Player
{
    QPoint pos;
    FieldState turn;
public:
    Player();
    void setPos(int x,int y);
    void setTurn(FieldState fState);
    QPoint getPos();
    int getX();
    int getY();
    FieldState getTurn();
    void turnLeft();
    void turnRight();
    void move();
    QPoint getNextPos();

};

#endif // PLAYER_H
