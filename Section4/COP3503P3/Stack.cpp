#include "Stack.h"

Stack::Stack()
{
    head = nullptr;
    tail = nullptr;
}

Stack::~Stack()
{
    Node *curr = head;
    Node *temp = nullptr;
    while (curr != nullptr)
    {
        temp = curr;
        curr = curr->next;
        delete temp;
    }
}

void Stack::push()
{
    if (head == nullptr)
    {
        head = new Node();
        tail = head;
    }
    else if (head == tail)
    {
        tail = new Node();
        tail->prev = head;
        head->next = tail;
    }
    else 
    {
        Node *temp = new Node();
        tail->next = new Node();
        temp->prev = tail;
        tail = temp;
    }
}

bool Stack::pop()
{
    Node *curr = tail;
    if (findDepth() == 0)
        return false;
    else
    {
        if (findDepth() == 1)
        {
            head = nullptr;
            tail = nullptr;
            delete curr;
        }
        else
        {
            tail = tail->prev;
            tail->next = nullptr;
            delete curr;
        }
        return true;
    }
}

int Stack::findDepth()
{
    int count = 0;
    Node *curr = head;
    while (curr != nullptr)
    {
        count++;
        curr = curr->next;
    }
    return count;
}

