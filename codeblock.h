#ifndef CODEBLOCK_H
#define CODEBLOCK_H
#include "action.h"

class CodeBlock
{
    Action action;
public:
    CodeBlock();
    void setAction(Action action);
    Action getAction();
};

#endif // CODEBLOCK_H
