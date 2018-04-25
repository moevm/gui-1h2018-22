#include "codeblock.h"

CodeBlock::CodeBlock()
{

}

void CodeBlock::setAction(Action action)
{
    this->action = action;
}

Action CodeBlock::getAction()
{
    return action;
}

void CodeBlock::setIterations(int iterations)
{
    this->iterations = iterations;
}

int CodeBlock::getIterations()
{
    return iterations;
}
