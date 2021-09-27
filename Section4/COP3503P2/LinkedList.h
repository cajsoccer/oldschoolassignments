#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <Node.h>
#include <iostream>

class LinkedList
{
private:
    Node *head;
    Node *tail;
public:
    LinkedList();
    ~LinkedList();
    void addNode();
    void printNodes();
    int getFrags();
    bool killProg(std::string name, int &size);
    bool insertProgFirst(std::string name, int size, int *failRet);
    bool insertProgWorst(std::string name, int size, int *failRet);
    bool insertProgBest(std::string name, int size, int *failRet);
    bool insertProgHandler(std::string name, int size, int *failRet, int type);
};

#endif // LINKEDLIST_H
