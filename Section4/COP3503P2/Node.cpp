#include "Node.h"

Node::Node()
{
    this->prog = "FREE";
    next = nullptr;
    prev = nullptr;
}

Node::~Node()
{
    delete next;
    delete prev;
}

std::string Node::getProg()
{
    return prog;
}
void Node::setProg(std::string prog)
{
    this->prog = prog;
}

Node* Node::getNext()
{
    return next;
}
void Node::setNext(Node *newAddr)
{
    next = newAddr;
}
Node* Node::getPrev()
{
    return prev;
}
void Node::setPrev(Node *newAddr)
{
    prev = newAddr;
}

