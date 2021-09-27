#include "LinkedList.h"

LinkedList::LinkedList()
{
    head = nullptr;
    tail = nullptr;
    for (int i = 1; i <= 32; i++)
        addNode();
}

LinkedList::~LinkedList()
{
    delete head;
    delete tail;
}

void LinkedList::addNode()
{
    if (head == nullptr && tail == nullptr)
    {
        head = new Node();
        tail = head;
    }
    else if (head == tail)
    {
        tail = new Node();
        head->setNext(tail);
        tail->setPrev(head);
    }
    else 
    {
        Node *newNode = new Node();
        tail->setNext(newNode);
        newNode->setPrev(tail);
        tail = newNode;
    }
}

void LinkedList::printNodes()
{
    Node *curr = head;
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 8; j++)
        {
            std::cout << curr->getProg() + "    ";
            curr = curr->getNext();
        }
        std::cout << std::endl;
    }
}

int LinkedList::getFrags()
{
    Node *curr = head;
    int frags = 0;
    bool currProg = false;
    if (curr->getProg() != "FREE")
    {
        currProg = true;
        frags++;
    }
    else
        currProg = false;
    while (curr != nullptr)
    {
        if (curr->getNext() != nullptr && currProg && curr->getNext()->getProg() == "FREE")
            currProg = false;
        else if (curr->getNext() != nullptr && !currProg && curr->getNext()->getProg() != "FREE")
        {
            currProg = true;
            frags++;
        }
        curr = curr->getNext();
    }
    return frags;
}

bool LinkedList::killProg(std::string name, int &size)
{
    Node *curr = head;
    bool found = false;
    while (curr)
    {
        if (curr->getProg() == name)
        {
            found = true;
            curr->setProg("FREE");
            size++;
        }
        curr = curr->getNext();
    }
    return found;
}

bool LinkedList::insertProgFirst(std::string name, int size, int *failRet)
{
    Node *curr = head;
    *failRet = 0;
    bool added = false;
    bool alreadyExists = false;
    while (curr != nullptr)
    {
        if (curr->getProg() == name)
        {
            alreadyExists = true;
            *failRet = 1;
        }
        curr = curr->getNext();
    }
    if (!alreadyExists)
    {
        curr = head;
        Node *posStart = head;
        bool currFree;
        int currFreeCount = 0;
        if (head->getProg() == "FREE")
        {
            currFree = true;
            currFreeCount++;
        }
        else
            currFree = false;
        while (curr != nullptr)
        {
            if (currFreeCount == 1)
                posStart = curr;
            if (currFreeCount == size && !added)
            {
                for (int i = 1; i <= size; i++)
                {
                    posStart->setProg(name);
                    posStart = posStart->getNext();
                }
                added = true;
                break;
            }
            if (curr->getNext() != nullptr && currFree && curr->getNext()->getProg() == "FREE")
                currFreeCount++;
            else if (curr->getNext() != nullptr && currFree && curr->getNext()->getProg() != "FREE")
            {
                currFree = false;
                currFreeCount = 0;
            }
            else if (curr->getNext() != nullptr && !currFree && curr->getNext()->getProg() == "FREE")
            {
                currFree = true;
                currFreeCount = 1;
            }
            curr = curr->getNext();
        }
    }
    if (!added && !alreadyExists)
        *failRet = 2;
    return added;
}

bool LinkedList::insertProgWorst(std::string name, int size, int *failRet)
{
    Node *curr = head;
    *failRet = 0;
    bool added = false;
    bool alreadyExists = false;
    while (curr != nullptr)
    {
        if (curr->getProg() == name)
        {
            alreadyExists = true;
            *failRet = 1;
        }
        curr = curr->getNext();
    }
    if (!alreadyExists)
    {
        curr = head;
        Node *posStart = head;
        Node *currBestPos = nullptr;
        bool currFree;
        int currFreeCount = 0;
        int bestFreeCount = 0;
        if (head->getProg() == "FREE")
        {
            currFree = true;
            currFreeCount++;
        }
        else
            currFree = false;
        while (curr != nullptr)
        {
            if (currFreeCount == 1)
                posStart = curr;
            if (currFreeCount >= bestFreeCount)
            {
                currBestPos = posStart;
                bestFreeCount = currFreeCount;
            }
            if (curr->getNext() != nullptr && currFree && curr->getNext()->getProg() == "FREE")
                currFreeCount++;
            else if (curr->getNext() != nullptr && currFree && curr->getNext()->getProg() != "FREE")
            {
                currFree = false;
                currFreeCount = 0;
            }
            else if (curr->getNext() != nullptr && !currFree && curr->getNext()->getProg() == "FREE")
            {
                currFree = true;
                currFreeCount = 1;
            }
            curr = curr->getNext();
        }
        if (bestFreeCount >= size && !added)
        {
            for (int i = 1; i <= size; i++)
            {
                currBestPos->setProg(name);
                currBestPos = currBestPos->getNext();
            }
            added = true;
        }
    }
    if (!added && !alreadyExists)
        *failRet = 2;
    return added;
}

bool LinkedList::insertProgBest(std::string name, int size, int *failRet)
{
    Node *curr = head;
    *failRet = 0;
    bool added = false;
    bool alreadyExists = false;
    while (curr != nullptr)
    {
        if (curr->getProg() == name)
        {
            alreadyExists = true;
            *failRet = 1;
        }
        curr = curr->getNext();
    }
    if (!alreadyExists)
    {
        int count = 1;
        curr = head;
        Node *posStart = head;
        Node *currBestPos = nullptr;
        bool currFree;
        int currFreeCount = 0;
        int bestFreeCount = 33;
        if (head->getProg() == "FREE")
        {
            currFree = true;
            currFreeCount++;
        }
        else
            currFree = false;
        while (curr != nullptr)
        {
            if (currFreeCount == 1)
                posStart = curr;
            if (currFree && currFreeCount <= bestFreeCount && currFreeCount >= size && (curr->getNext() == nullptr || curr->getNext()->getProg() != "FREE"))
            {
                currBestPos = posStart;
                bestFreeCount = currFreeCount;
            }
            if (curr->getNext() != nullptr && currFree && curr->getNext()->getProg() == "FREE")
                currFreeCount++;
            else if (curr->getNext() != nullptr && currFree && curr->getNext()->getProg() != "FREE")
            {
                currFree = false;
                currFreeCount = 0;
            }
            else if (curr->getNext() != nullptr && !currFree && curr->getNext()->getProg() == "FREE")
            {
                currFree = true;
                currFreeCount = 1;
            }
            curr = curr->getNext();
            count++;
        }
        if (bestFreeCount >= size && !added)
        {
            for (int i = 1; i <= size; i++)
            {
                currBestPos->setProg(name);
                currBestPos = currBestPos->getNext();
            }
            added = true;
        }
    }
    if (!added && !alreadyExists)
        *failRet = 2;
    return added;
}

bool LinkedList::insertProgHandler(std::string name, int size, int *failRet, int type)
{
    if (type == 1)
        return LinkedList::insertProgFirst(name, size, failRet);
    else if (type == 2)
        return LinkedList::insertProgWorst(name, size, failRet);
    else if (type == 3)
        return LinkedList::insertProgBest(name, size, failRet);
    else
        return false;
}