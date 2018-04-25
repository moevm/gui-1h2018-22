#ifndef CODEBLOCK_H
#define CODEBLOCK_H
#include "action.h"

class CodeBlock
{
    Action action;
    int iterations;
public:
    CodeBlock(Action action);
    Action getAction();
    void setIterations(int iterations);
    int getIterations();
};

#endif // CODEBLOCK_H
