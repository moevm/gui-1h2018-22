#include "player.h"

Player::Player()
{

}

void Player::setPos(int x, int y)
{
    pos = QPoint(x, y);
}

void Player::setTurn(FieldState fState)
{
    turn = fState;
}

QPoint Player::getPos()
{
    return pos;
}

int Player::getX()
{
    return pos.x();
}
int Player::getY()
{
    return pos.y();
}
FieldState Player::getTurn()
{
    return turn;
}

void Player::turnLeft()
{
    switch (turn) {
    case PLAYER_RIGHT:
    {
        turn = PLAYER_DOWN;
        break;
    }
    case PLAYER_DOWN:
    {
        turn = PLAYER_LEFT;
        break;
    }
    case PLAYER_LEFT:
    {
        turn = PLAYER_UP;
        break;
    }
    case PLAYER_UP:
    {
        turn = PLAYER_RIGHT;
        break;
    }
    }
}

void Player::turnRight()
{
    switch (turn) {
    case PLAYER_RIGHT:
    {
        turn = PLAYER_UP;
        break;
    }
    case PLAYER_DOWN:
    {
        turn = PLAYER_RIGHT;
        break;
    }
    case PLAYER_LEFT:
    {
        turn = PLAYER_DOWN;
        break;
    }
    case PLAYER_UP:
    {
        turn = PLAYER_LEFT;
        break;
    }
    }
}

void Player::move()
{
    pos = getNextPos();
}

QPoint Player::getNextPos()
{
    QPoint nextPos;
    switch (turn) {
    case PLAYER_RIGHT:
    {
        nextPos = pos + QPoint(0, 1);
        break;
    }
    case PLAYER_DOWN:
    {
        nextPos = pos - QPoint(1, 0);
        break;
    }
    case PLAYER_LEFT:
    {
        nextPos = pos - QPoint(0, 1);
        break;
    }
    case PLAYER_UP:
    {
        nextPos = pos + QPoint(1, 0);
        break;
    }
    }
}
