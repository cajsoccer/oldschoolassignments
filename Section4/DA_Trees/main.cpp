#include <iostream>
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
    void setPrev(Node* p){prev = p;}
    void setLeft(Node* l){left = l;}
    void setRight(Node* r){right = r;}
    Node(){}
    Node(int v)
    {
        val = v;
        prev = nullptr;
        left = nullptr;
        right = nullptr;
    }
};

class BinTree
{
private:
    Node* root;
public:
    Node* getRoot(){return root;}
    BinTree()
    {
        root = nullptr;
    }
    void insert(int x)
    {
        Node* newNode = new Node(x);
        if (!root)
            root = newNode;
        else
        {
            Node* curr = root;
            while (curr)
            {
                if (x < curr->getVal())
                {
                    if (!curr->getLeft())
                    {
                        curr->setLeft(newNode);
                        newNode->setPrev(curr);
                        break;
                    }
                    else
                        curr = curr->getLeft();
                }
                else if (x > curr->getVal())
                {
                    if (!curr->getRight())
                    {
                        curr->setRight(newNode);
                        newNode->setPrev(curr);
                        break;
                    }
                    else
                        curr = curr->getRight();
                }
                else
                {
                    delete newNode;
                    return;
                }
            }
            balTree(root);
        }
    }
    bool find(int x)
    {
        if (!root)
            return false;
        Node* curr = root;
        while (curr)
        {
            if (curr->getVal() == x)
                return true;
            else if (curr->getVal() < x)
                curr = curr->getRight();
            else
                curr = curr->getLeft();
        }
        return false;
    }
    bool del(int x)
    {
        if (!root)
            return false;
        Node* curr = root;
        while (curr)
        {
            if (curr->getVal() < x)
                curr = curr->getRight();
            else if (curr->getVal() > x)
                curr = curr->getLeft();
            else
            {
                if (!curr->getLeft() && !curr->getRight())
                {
                    if (curr == root)
                        root = nullptr;
                    else
                    {
                        if (curr->getPrev()->getVal() > curr->getVal())
                            curr->getPrev()->setLeft(nullptr);
                        else
                            curr->getPrev()->setRight(nullptr);
                    }
                }
                else if (!curr->getLeft() && curr->getRight())
                {
                    if (curr == root)
                        root = root->getRight();
                    else
                    {
                        if (curr->getPrev()->getVal() > curr->getVal())
                            curr->getPrev()->setLeft(curr->getRight());
                        else
                            curr->getPrev()->setRight(curr->getRight());
                        curr->getRight()->setPrev(curr->getPrev());
                    }
                }
                else if (curr->getLeft() && !curr->getRight())
                {
                    if (curr == root)
                        root = root->getLeft();
                    else
                    {
                        if (curr->getPrev()->getVal() > curr->getVal())
                            curr->getPrev()->setLeft(curr->getLeft());
                        else
                            curr->getPrev()->setRight(curr->getLeft());
                        curr->getLeft()->setPrev(curr->getPrev());
                    }
                }
                else
                {
                    curr = curr->getLeft();
                    PreOrderPredSwap(curr);
                }
                delete curr;
                balTree(root);
                return true;
            }
        }
        return false;
    }
    void PreOrderPredSwap(Node* &curr)
    {
        Node* swapNode = curr->getPrev();
        while (curr->getRight())
            curr = curr->getRight();
        swapNode->setVal(curr->getVal());
        if (curr->getLeft())
        {
            if (curr->getPrev() == swapNode)
                swapNode->setLeft(curr->getLeft());
            else 
                curr->getPrev()->setRight(curr->getLeft());
        }
        else
        {
            if (curr->getPrev() == swapNode)
                swapNode->setLeft(nullptr);
            else
                curr->getPrev()->setRight(nullptr);
        }
    }
    void printPreOrder(Node* curr)
    {
        if (!curr)
            return;
        std::cout << curr->getVal() << " ";
        Node* next;
        if (curr->getLeft())
        {
            next = curr->getLeft();
            printPreOrder(next);
        }
        if (curr->getRight())
        {
            next = curr->getRight();
            printPreOrder(next);
        }
    }
    void printInOrder(Node* curr)
    {
        if (!curr)
            return;
        Node* next;
        if (curr->getLeft())
        {
            next = curr->getLeft();
            printInOrder(next);
        }
        std::cout << curr->getVal() << " ";
        if (curr->getRight())
        {
            next = curr->getRight();
            printInOrder(next);
        }
    }
    void printPostOrder(Node* curr)
    {
        if (!curr)
            return;
        Node* next;
        if (curr->getLeft())
        {
            next = curr->getLeft();
            printPostOrder(next);
        }
        if (curr->getRight())
        {
            next = curr->getRight();
            printPostOrder(next);
        }
        std::cout << curr->getVal() << " ";
    }
    int leafCount(Node* curr)
    {
        if (!root)
            return 0;
        static int count = 0;
        if (!curr->getLeft() && !curr->getRight())
            count++;
        Node* next;
        if (curr->getLeft())
        {
            next = curr->getLeft();
            leafCount(next);
        }
        if (curr->getRight())
        {
            next = curr->getRight();
            leafCount(next);
        }
        int retCount = count;
        if (curr == root)
            count = 0;
        return retCount;
    }
    int heightCount(Node* curr)
    {
        static int currHeight = 0;
        static int maxHeight = 0;
        if (!curr)
            return 0;
        currHeight++;
        if (currHeight > maxHeight)
            maxHeight = currHeight;
        int locMax = maxHeight;
        heightCount(curr->getLeft());
        heightCount(curr->getRight());
        currHeight--;
        int retMax = 0;
        if (locMax == 1)
        {
            retMax = maxHeight;
            currHeight = 0;
            maxHeight = 0;
        }
        return retMax;
    }
    int nodeCount(Node* curr)
    {
        if (!root)
            return 0;
        static int count = 0;
        count++;
        if (curr->getLeft())
            nodeCount(curr->getLeft());
        if (curr->getRight())
            nodeCount(curr->getRight());
        int retCount = count;
        if (curr == root)
            count = 0;
        return retCount;
    }
    int sumNodes(Node* curr)
    {
        if (!curr)
            return 0;
        static int sum = 0;
        sum += curr->getVal();
        sumNodes(curr->getLeft());
        sumNodes(curr->getRight());
        int retSum = sum;
        if (curr == root)
            sum = 0;
        return retSum;
    }
    int getBalFac(Node* curr)
    {
        return (heightCount(curr->getLeft()) - heightCount(curr->getRight()));
    }
    void balTree(Node* curr)
    {
        if (!curr)
            return;
        if (getBalFac(curr) > 1)
        {
            if (getBalFac(curr->getLeft()) > 0)
                balSubTree(curr, 1);
            else
                balSubTree(curr, 2);
        }
        else if (getBalFac(curr) < -1)
        {
            if (getBalFac(curr->getRight()) > 0)
                balSubTree(curr, 3);
            else
                balSubTree(curr, 4);
        }
        balTree(curr->getLeft());
        balTree(curr->getRight());
    }
    void balSubTree(Node* curr, int type)
    {
        //1=LL,2=LR,3=RL,4=RR
        std::cout << "rot type: " << type << std::endl;
        if (type == 1)
        {
            Node* nxt = curr->getLeft();
            if (curr->getPrev() && curr->getPrev()->getLeft() == curr)
                curr->getPrev()->setLeft(nxt);
            else if (curr->getPrev() && curr->getPrev()->getRight() == curr)
                curr->getPrev()->setRight(nxt);
            nxt->setPrev(curr->getPrev());
            if (nxt->getRight())
                nxt->getRight()->setPrev(curr);
            curr->setLeft(nxt->getRight());
            curr->setPrev(nxt);
            nxt->setRight(curr);
            if (curr == root)
                root = nxt;
        }
        else if (type == 2)
        {
            Node* nxt = curr->getLeft();
            Node* nxt2 = nxt->getRight();
            if (curr->getPrev() && curr->getPrev()->getLeft() == curr)
                curr->getPrev()->setLeft(nxt2);
            else if (curr->getPrev() && curr->getPrev()->getRight() == curr)
                curr->getPrev()->setRight(nxt2);
            nxt2->setPrev(curr->getPrev());
            if (nxt2->getRight())
                nxt2->getRight()->setPrev(curr);
            curr->setLeft(nxt2->getRight());
            if (nxt2->getLeft())
                nxt2->getLeft()->setPrev(nxt);
            nxt->setRight(nxt2->getLeft());
            nxt->setPrev(nxt2);
            nxt2->setRight(curr);
            nxt2->setLeft(nxt);
            curr->setPrev(nxt2);
            if (curr == root)
                root = nxt2;
        }
        else if (type == 3)
        {
            Node* nxt = curr->getRight();
            Node* nxt2 = nxt->getLeft();
            if (curr->getPrev() && curr->getPrev()->getLeft() == curr)
                curr->getPrev()->setLeft(nxt2);
            else if (curr->getPrev() && curr->getPrev()->getRight() == curr)
                curr->getPrev()->setRight(nxt2);
            nxt2->setPrev(curr->getPrev());
            if (nxt2->getLeft())
                nxt2->getLeft()->setPrev(curr);
            curr->setRight(nxt2->getLeft());
            if (nxt2->getRight())
                nxt2->getRight()->setPrev(nxt);
            nxt->setLeft(nxt2->getRight());
            nxt->setPrev(nxt2);
            nxt2->setLeft(curr);
            nxt2->setRight(nxt);
            curr->setPrev(nxt2);
            if (curr == root)
                root = nxt2;
        }
        else if (type == 4)
        {
            Node* nxt = curr->getRight();
            if (curr->getPrev() && curr->getPrev()->getLeft() == curr)
                curr->getPrev()->setLeft(nxt);
            else if (curr->getPrev() && curr->getPrev()->getRight() == curr)
                curr->getPrev()->setRight(nxt);
            nxt->setPrev(curr->getPrev());
            if (nxt->getLeft())
                nxt->getLeft()->setPrev(curr);
            curr->setRight(nxt->getLeft());
            curr->setPrev(nxt);
            nxt->setLeft(curr);
            if (curr == root)
                root = nxt;
        }
    }
};

class Node
{
private:
    int data;
    Node* left;
    Node* right;
};

int main()
{
    BinTree t;
    //std::array<int, 9> nums = {9,15,5,20,16,8,12,3,6};
    //std::array<int, 9> nums = {30,20,10,25,40,35,45,42,43};
    //std::array<int, 5> nums = {50,10,40,20,30};
    //std::array<int, 9> nums = {30,20,10,15,25,40,50,55,60};
    //std::array<int, 8> nums = {3,1,4,5,7,2,6,10};
    std::array<int, 3> nums = {10,5,2};
    for (auto num: nums)
        t.insert(num);
    //t.del(40);
    t.printInOrder(t.getRoot());
    std::cout << std::endl;
    std::cout << "20 is in the tree?: " << t.find(20) << std::endl;
    std::cout << "The number of leaf nodes in the tree is: " << t.leafCount(t.getRoot()) << std::endl;
    std::cout << "The height of the tree is: " << t.heightCount(t.getRoot()) << std::endl;
    std::cout << "The number of nodes in the tree is: " << t.nodeCount(t.getRoot()) << std::endl;
    std::cout << "The sum of the nodes in the tree is: " << t.sumNodes(t.getRoot()) << std::endl;
    std::cout << "The root of the tree is : " << t.getRoot()->getVal() << std::endl;
    return 0;
}