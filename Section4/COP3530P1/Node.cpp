#include "Node.h"

Node::Node(int row, int col, int val)
{
    this->row = row;
    this->col = col;
    this->val = val;
}

Node::~Node()
{
}

int Node::getRow()
{
    return row;
}

void Node::setRow(int row)
{
    this->row = row;
}

int Node::getCol()
{
    return col;
}

void Node::setCol(int col)
{
    this->col = col;
}

int Node::getVal()
{
    return val;
}

void Node::setVal(int val)
{
    this->val = val;
}