#ifndef STACK_H
#define STACK_H
#include <Node.h>

class Stack
{
public:
    Node *head;
    Node *tail;
    Stack();
    ~Stack();
    void push();
    bool pop();
    int findDepth();
};

#endif // STACK_H
