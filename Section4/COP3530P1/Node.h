#ifndef NODE_H
#define NODE_H

class Node
{
private:
    int row;
    int col;
    int val;
public:
    Node(int row, int col, int val);
    ~Node();
    int getRow();
    void setRow(int row);
    int getCol();
    void setCol(int col);
    int getVal();
    void setVal(int val);
};

#endif // NODE_H
