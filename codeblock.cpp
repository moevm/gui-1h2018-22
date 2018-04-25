#include "codeblock.h"

CodeBlock::CodeBlock(Action action)
{
    this->action = action;
}

Action CodeBlock::getAction()
{
    return action;
}

void CodeBlock::setIterations(int iterations)
{
    if(action == LOOP_END)
        this->iterations = iterations;

}

int CodeBlock::getIterations()
{
    if(action == LOOP_END)
        return iterations;
}
