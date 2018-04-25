#include "loop.h"

Loop::Loop(int position)
{
    this->position = position;
    index = 0;
}

void Loop::increment()
{
    index++;
}

int Loop::getIndex()
{
    return index;
}
