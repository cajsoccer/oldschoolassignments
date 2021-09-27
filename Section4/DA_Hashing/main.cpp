#include <iostream>
#include <array>

class Node
{
private:
    Node* prev;
    Node* next;
    int val;
public:
    Node(int v = 0)
    {
        prev = nullptr;
        next = nullptr;
        val = v;
    }
    Node* getPrev(){return prev;}
    Node* getNext(){return next;}
    int getVal(){return val;}
    void setPrev(Node* addr){prev = addr;}
    void setNext(Node* addr){next = addr;}
    void setVal(int x){val = x;}
};

class HashTable
{
private: 
    std::array<Node*, 10> table;
public:
    HashTable()
    {
        for (int i = 0; i < 10; i++)
            table[i] = nullptr;
    }
    std::array<Node*,10> getTable(){return table;}
    bool search(int x)
    {
        int index = x % 10;
        Node* curr = table[index];
        while (curr)
        {
            if (curr->getVal() == x)
                return true;
            else
                curr = curr->getNext();
        }
        return false;
    }
    bool insert(int x)
    {
        if (search(x))
            return false;
        else
        {
            Node* newNode = new Node(x);
            int index = x % 10;
            if (table[index] == nullptr)
                table[index] = newNode;
            else
            {
                Node* curr = table[index];
                while (curr->getNext())
                    curr = curr->getNext();
                curr->setNext(newNode);
                newNode->setPrev(curr);
            }
            return true;
        }
    }
};

int main()
{
    HashTable h;
    std::cout << h.search(22) << std::endl;
    h.insert(12);
    h.insert(22);
    h.insert(42);
    std::cout << h.search(22) << std::endl;
    return 0;
}