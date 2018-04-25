#include "loop.h"

Loop::Loop()
{

}

void Loop::setPosition(int pos)
{
    position = pos;
}

int Loop::getPosition()
{
    return position;
}

void Loop::setIndex(int index)
{
    this->index = index;
}

int Loop::getIndex()
{
    return index;
}
