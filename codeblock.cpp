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
