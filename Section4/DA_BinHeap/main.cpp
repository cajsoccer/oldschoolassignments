#include <iostream>
#include <math.h>
#include <vector>
#include <array>

class Node
{
private:
    int val;
    Node* prev;
    Node* left;
    Node* right;
public:
    int getVal(){return val;}
    Node* getPrev(){return prev;}
    Node* getLeft(){return left;}
    Node* getRight(){return right;}
    void setVal(int x){val = x;}
    void setPrev(Node* x) {prev = x;}
    void setLeft(Node* x) {left = x;}
    void setRight(Node* x) {right = x;}
    Node(int x = 0)
    {
        val = x;
        prev = nullptr;
        left = nullptr;
        right = nullptr;
    }
};

class BinHeap
{
private:
    int size;
    int nodeCount;
    int height;
    int bottomCount;
    Node* head;
public: 
    Node* getHead(){return head;}
    BinHeap(int s = 7)
    {
        size = s;
        nodeCount = 0;
        height = 0;
        bottomCount = 0;
        head = nullptr;
    }
    void traverseHeapInsert(Node* curr, Node* newNode, int x)
    {
        static int currHeight = 0;
        static bool added = false;
        if (!curr || added)
            return;
        currHeight++;
        if (currHeight == height - 1)
        {
            if (!curr->getLeft())
            {
                curr->setLeft(newNode);
                newNode->setPrev(curr);
                nodeCount++;
                bottomCount++;
                added = true;
            }
            else if (!curr->getRight())
            {
                curr->setRight(newNode);
                newNode->setPrev(curr);
                nodeCount++;
                bottomCount++;
                added = true;
            }
        }
        else
        {
            traverseHeapInsert(curr->getLeft(), newNode, x);
            traverseHeapInsert(curr->getRight(), newNode, x);
        }
        currHeight--;
        if (curr == head)
            added = false;
    }
    bool insert(int x)
    {
        if (nodeCount == size)
            return false;
        Node* newNode = new Node(x);
        if (!head)
        {
            head = newNode;
            nodeCount++;
            height++;
            bottomCount++;
            balNodesIns(newNode);
            return true;
        }
        if (bottomCount == pow(2, height - 1))
        {
            Node* curr = head;
            while (curr->getLeft())
                curr = curr->getLeft();
            curr->setLeft(newNode);
            newNode->setPrev(curr);
            nodeCount++;
            height++;
            bottomCount = 1;
        }
        else
            traverseHeapInsert(head, newNode, x);
        balNodesIns(newNode);
        return true;
    }
    void balNodesIns(Node* node)
    {
        while (node->getPrev())
        {
            if (node->getVal() < node->getPrev()->getVal())
            {
                int temp = node->getVal();
                node->setVal(node->getPrev()->getVal());
                node->getPrev()->setVal(temp);
            }
            else
                break;
            node = node->getPrev();
        }
    }
    void findBottomRight(Node* curr, Node* &botRight)
    {
        static int currHeight = 0;
        static bool found = false;
        if (curr == head && !curr->getLeft() && !curr->getRight())
        {
            botRight = curr;
            return;
        }
        if (!curr || found)
            return;
        currHeight++;
        if (currHeight == height - 1)
        {
            if (curr->getRight())
            {
                botRight = curr->getRight();
                found = true;
            }
            else if (curr->getLeft())
            {
                botRight = curr->getLeft();
                found = true;
            }
        }
        else
        {
            findBottomRight(curr->getRight(), botRight);
            findBottomRight(curr->getLeft(), botRight);
        }
        currHeight--;
        if (currHeight == 0)
            found = false;
    }
    int del()
    {
        if (!head)
            return -1;
        else
        {
            int headVal = head->getVal();
            Node* botRight = nullptr;
            findBottomRight(head, botRight);
            if (botRight == head)
                head = nullptr;
            else
            {
                head->setVal(botRight->getVal());
                if (botRight->getPrev()->getLeft() == botRight)
                    botRight->getPrev()->setLeft(nullptr);
                else if (botRight->getPrev()->getRight() == botRight)
                    botRight->getPrev()->setRight(nullptr);
                Node* curr = head;
                while (curr->getLeft())
                {
                    if (curr->getRight())
                    {
                        if (curr->getVal() <= curr->getRight()->getVal() && curr->getVal() <= curr->getLeft()->getVal())
                            break;
                        else if (curr->getVal() > curr->getRight()->getVal() && curr->getVal() > curr->getLeft()->getVal())
                        {
                            if (curr->getRight()->getVal() > curr->getLeft()->getVal())
                            {
                                int temp = curr->getVal();
                                curr->setVal(curr->getLeft()->getVal());
                                curr->getLeft()->setVal(temp);
                                curr = curr->getLeft();
                            }
                            else
                            {
                                int temp = curr->getVal();
                                curr->setVal(curr->getRight()->getVal());
                                curr->getRight()->setVal(temp);
                                curr = curr->getRight();
                            }
                        }
                        else if (curr->getVal() > curr->getLeft()->getVal())
                        {
                            int temp = curr->getVal();
                            curr->setVal(curr->getLeft()->getVal());
                            curr->getLeft()->setVal(temp);
                            curr = curr->getLeft();
                        }
                        else if (curr->getVal() > curr->getRight()->getVal())
                        {
                            int temp = curr->getVal();
                            curr->setVal(curr->getRight()->getVal());
                            curr->getRight()->setVal(temp);
                            curr = curr->getRight();
                        }
                    }
                    else
                    {
                        if (curr->getVal() <= curr->getLeft()->getVal())
                            break;
                        else
                        {
                            int temp = curr->getVal();
                            curr->setVal(curr->getLeft()->getVal());
                            curr->getLeft()->setVal(temp);
                            curr = curr->getLeft();
                        }
                    }
                }
            }
            delete botRight;
            nodeCount--;
            bottomCount--;
            if (nodeCount == 0)
            {
                head = nullptr;
                height = 0;
                return headVal;
            }
            if (bottomCount == 0)
            {
                height--;
                bottomCount = pow(2, height - 1);
            }
            return headVal;
        }
    }
    std::vector<int> heapSort()
    {
        std::vector<int> sortedHeap;
        while (head)
            sortedHeap.push_back(del());
        return sortedHeap;
    }
    void printPreOrder(Node* curr)
    {
        if (!curr)
            return;
        std::cout << curr->getVal() << std::endl;
        printPreOrder(curr->getLeft());
        printPreOrder(curr->getRight());
        if (curr == head)
            std::cout << std::endl;
    }
};

int main()
{
    BinHeap h(15);
    //std::array<int, 7> elems = {5,10,15,20,25,28,29};
    //std::array<int, 7> elems = {40,35,15,10,30,25,5};
    std::array<int,7> elems = {10,20,30,25,5,40,35};
    for (auto e: elems)
        h.insert(e);
    h.printPreOrder(h.getHead());
    std::vector<int> list = h.heapSort();
    for (auto e: list)
        std::cout << e << " ";
    std::cout << std::endl;
    return 0;
}