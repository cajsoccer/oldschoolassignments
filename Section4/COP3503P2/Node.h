#ifndef NODE_H
#define NODE_H
#include <string>

class Node
{
private:
    std::string prog;
    Node *next;
    Node *prev;
public:
    Node();
    ~Node();
    std::string getProg();
    void setProg(std::string prog);
    Node* getNext();
    void setNext(Node *newAddr);
    Node* getPrev();
    void setPrev(Node *newAddr);
};

#endif // NODE_H