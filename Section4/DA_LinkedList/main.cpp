#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <array>
#include <math.h>

class Node
{
private:
    int val;
    Node* next;
public:
    Node()
    {
        val = 0;
        next = nullptr;
    }
    Node(int val)
    {
        this->val = val;
        next = nullptr;
    }
    ~Node(){};
    int getVal(){return val;}
    Node* getNext(){return next;}
    void setNext(Node* next){this->next = next;}
};

class LinkedList
{
private:
    Node* head;
public:
    LinkedList()
    {
        head = nullptr;
    }
    ~LinkedList()
    {
        Node* temp = nullptr;
        Node* curr = head;
        while (curr != nullptr)
        {
            temp = curr;
            if (curr->getNext() != nullptr)
                curr = curr->getNext();
            else
                curr = nullptr;
            delete temp;
        }
    }
    void insertNode(int x)
    {
        if (head == nullptr)
            head = new Node(x);
        else
        {
            Node* curr = head;
            while (curr->getNext() != nullptr)
                curr = curr->getNext();
            Node* newNode = new Node(x);
            curr->setNext(newNode);
        }
    }
    void insert(int index, int x)
    {
        if (index < 0 || index > getLen())
            return;
        Node* newNode = new Node(x);
        if (index == 0)
        {
            newNode->setNext(head);
            head = newNode;
        }
        else
        {
            int pos = 1;
            Node* curr = head;
            while (curr != nullptr)
            {
                if (pos == index)
                {
                    newNode->setNext(curr->getNext());
                    curr->setNext(newNode);
                    return;
                }
                else
                {
                    pos++;
                    curr = curr->getNext();
                }
            }
        }
    }
    void insertSorted(int x)
    {
        Node* curr = head;
        Node* newNode = new Node(x);
        if (!curr)
            head = newNode;
        else
        {
            while (curr)
            {
                if (curr == head)
                {
                    if (x < curr->getVal())
                    {
                        newNode->setNext(head);
                        head = newNode;
                        break;
                    }
                    else if (x >= curr->getVal() && x <= curr->getNext()->getVal())
                    {
                        newNode->setNext(curr->getNext());
                        curr->setNext(newNode);
                        break;
                    }
                }
                else if (!curr->getNext())
                {
                    curr->setNext(newNode);
                    break;
                }
                else 
                {
                    if (x >= curr->getVal() && x <= curr->getNext()->getVal())
                    {
                        newNode->setNext(curr->getNext());
                        curr->setNext(newNode);
                        break;
                    }
                }
                curr = curr->getNext();
            }
        }
    }
    void insertArray(int *x, int size)
    {
        for (int i = 0; i < size; i++)
            insertNode(x[i]);
    }
    void append(int x)
    {
        Node* curr = head;
        Node* newNode = new Node(x);
        if (!curr)
            head = newNode;
        else
        {
            while (curr->getNext())
                curr = curr->getNext();
            curr->setNext(newNode);
        }
    }
    int getLen()
    {
        int len = 0;
        Node *curr = head;
        while (curr != nullptr)
        {
            len++;
            curr = curr->getNext();
        }
        return len;
    }
    int getSum()
    {
        int sum = 0;
        Node *curr = head;
        while (curr != nullptr)
        {
            sum+= curr->getVal();
            curr = curr->getNext();
        }
        return sum;
    }
    int getMax()
    {
        Node* curr = head;
        int max = -2147483648;
        while (curr != nullptr)
        {
            if (curr->getVal() > max)
                max = curr->getVal();
            curr = curr->getNext();
        }
        return max;
    }
    int search(int key)
    {
        Node* curr = head;
        int index = 1;
        bool found = false;
        while (curr != nullptr)
        {
            if (curr->getVal() == key)
            {
                found = true;
                break;
            }
            else
            {
                index++;
                curr = curr ->getNext();
            }
        }
        if (found)
            return index;
        else
            return -1;
    }
    void deleteNode(int x)
    {
        if (!head)
            return;
        if (!head->getNext() && x == 1)
        {
            Node* temp = head;
            head = nullptr;
            delete temp;
            return;
        }
        Node* curr = head;
        if (x == 1)
        {
            head = curr->getNext();
            delete curr;
        }
        else
        {
            int pos = 1;
            while (curr->getNext())
            {
                if (pos + 1 == x)
                {
                    Node* temp = curr->getNext();
                    if (curr->getNext()->getNext())
                        curr->setNext(curr->getNext()->getNext());
                    else
                        curr->setNext(nullptr);
                    delete temp;
                    return;
                }
                curr = curr->getNext();
                pos++;
            }
        }
    }
    void printList()
    {
        Node* curr = head;
        while (curr != nullptr)
        {
            std::cout << curr->getVal() << " ";
            curr = curr->getNext();
        }
        std::cout << std::endl;
    }
    void printListRec()
    {
        static Node* curr = head;
        if (curr != nullptr)
        {
            std::cout << curr->getVal() << " ";
            curr = curr->getNext();
            printListRec();
        }
        else
        {
            curr = head;
            std::cout << std::endl;
        }
    }
    bool isSorted()
    {
        Node* curr = head;
        if (!head)
            return true;
        else if (!head->getNext())
            return true;
        else
        {
            while (curr->getNext())
            {
                if (curr->getNext()->getVal() - curr->getVal() < 0)
                    return false;
                curr = curr->getNext();
            }
            return true;
        }
    }
    void removeDupsSorted()
    {
        if (!head)
            return;
        Node* curr = head;
        while (curr->getNext())
        {
            if (curr->getVal() == curr->getNext()->getVal())
            {
                Node* temp = curr->getNext();
                if (curr->getNext()->getNext())
                    curr->setNext(curr->getNext()->getNext());
                else
                    curr->setNext(nullptr);
                delete temp;
            }
            else
                curr = curr->getNext();
        }
    }
    void reverse()
    {
        if (!head)
            return;
        if (!head->getNext())
            return;
        int len = getLen();
        Node* arr[len];
        Node* curr = head;
        int i = 0;
        while (curr)
        {
            arr[i] = curr;
            i++;
            curr = curr->getNext();
        }
        for (int i = len - 1; i >= 0; i--)
        {
            if (i == 0)
                arr[i]->setNext(nullptr);
            else
                arr[i]->setNext(arr[i-1]);
        }
        head = arr[len-1];
    }
    LinkedList concat(const LinkedList* l2)
    {
        LinkedList newList;
        Node* curr = head;
        while (curr)
        {
            newList.append(curr->getVal());
            curr = curr->getNext();
        }
        curr = l2->head;
        while (curr)
        {
            newList.append(curr->getVal());
            curr = curr->getNext();
        }
        return newList;
    }
    LinkedList merge(const LinkedList* l2)
    {
        LinkedList newList;
        Node* curr1 = head;
        Node* curr2 = l2->head;
        while (curr1 && curr2)
        {
            if (curr1->getVal() <= curr2->getVal())
            {
                newList.append(curr1->getVal());
                curr1 = curr1->getNext();
            }
            else
            {
                newList.append(curr2->getVal());
                curr2 = curr2->getNext();
            }
        }
        while (curr1)
        {
            newList.append(curr1->getVal());
            curr1 = curr1->getNext();
        }
        while (curr2)
        {
            newList.append(curr2->getVal());
            curr2 = curr2->getNext();
        }
        return newList;
    }
    bool isLoop()
    {
        if (!head)
            return false;
        if (!head->getNext())
            return false;
        Node* p = head;
        Node* q = head;
        while (true)
        {
            q = p->getNext()->getNext();
            p = p->getNext();
            if (p == nullptr || q == nullptr)
                return false;
            else if (p == q)
                return true;
        }
    }
};

class CircularLinkedList
{
private:
    Node* head;
public:
    CircularLinkedList()
    {
        head = nullptr;
    }
    CircularLinkedList(int A[], int n)
    {
        head = nullptr;
        for (int i = 0; i < n; i++)
            append(A[i]);
    }
    void append(int x)
    {
        Node* newNode = new Node(x);
        if (!head)
        {
            head = newNode;
        }
        else if (!head->getNext())
        {
            head->setNext(newNode);
            newNode->setNext(head);
        }
        else
        {
            newNode->setNext(head->getNext());
            head->setNext(newNode);
        }
    }
    void printList()
    {
        Node* curr = head;
        do 
        {
            std::cout << curr->getVal() << " ";
            curr = curr->getNext();
        } while (curr != head);
        std::cout << std::endl;
    }
};

class DubNode
{
private:
    DubNode* prev;
    DubNode* next;
    int val;
public:
    DubNode()
    {
        prev = nullptr;
        next = nullptr;
        val = 0;
    }
    DubNode(int x)
    {
        prev = nullptr;
        next = nullptr;
        val = x;
    }
    DubNode* getPrev(){return prev;}
    DubNode* getNext(){return next;}
    int getVal(){return val;}
    void setPrev(DubNode* p){prev = p;}
    void setNext(DubNode* n){next = n;}
};

class DubLinkedList
{
private:
    DubNode* head;
    DubNode* tail;
public:
    DubLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }
    void append(int x)
    {
        DubNode* newNode = new DubNode(x);
        if (!head)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->setNext(newNode);
            newNode->setPrev(tail);
            tail = newNode;
        }
    }
    DubNode* getHead(){return head;}
    DubNode* getTail(){return tail;}
    void insert(int index, int x)
    {
        if (index < 0 || index > length())
            return;
        DubNode* newNode = new DubNode(x);
        if (!head)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            if (index == 0)
            {
                newNode->setNext(head);
                head->setPrev(newNode);
                head = newNode;
            }
            else if (index == length())
            {
                tail->setNext(newNode);
                newNode->setPrev(tail);
                tail = newNode;
            }
            else
            {
                DubNode* curr = head;
                int pos = 1;
                while (pos != index)
                {
                    curr = curr->getNext();
                    pos++;
                }
                curr->getNext()->setPrev(newNode);
                newNode->setNext(curr->getNext());
                curr->setNext(newNode);
                newNode->setPrev(curr);
            }
        }
    }
    void deleteNode(int index)
    {
        if (index <= 0 || index > length())
            return;
        if (!head)
            return;
        else if (!head->getNext())
        {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            if (index == 1)
            {
                DubNode* curr = head;
                head = head->getNext();
                head->setPrev(nullptr);
                delete curr;
            }
            else if (index == length())
            {
                DubNode* curr = tail;
                tail = tail->getPrev();
                tail->setNext(nullptr);
                delete curr;
            }
            else
            {
                DubNode* curr = head;
                int pos = 1;
                while (pos != index)
                {
                    pos++;
                    curr = curr->getNext();
                }
                curr->getPrev()->setNext(curr->getNext());
                curr->getNext()->setPrev(curr->getPrev());
                delete curr;
            }
        }
    }
    int length()
    {
        DubNode* curr = head;
        int len = 0;
        while (curr)
        {
            len++;
            curr = curr->getNext();
        }
        return len;
    }
    void print()
    {
        DubNode* curr = head;
        while (curr)
        {
            std::cout << curr->getVal() << " ";
            curr = curr->getNext();
        }
        std::cout << std::endl;
    }
    void reverse()
    {
        if (!head)
            return;
        else if (!head->getNext())
            return;
        else
        {
            DubLinkedList revList;
            while (true)
            {
                if (tail == head)
                {
                    revList.append(tail->getVal());
                    delete tail;
                    break;
                }
                else
                {
                    DubNode* temp = tail;
                    revList.append(tail->getVal());
                    tail = tail->getPrev();
                    tail->setNext(nullptr);
                    delete temp;
                }
            }
            head = revList.getHead();
            tail = revList.getTail();
        }
    }
    int middle()
    {
        if (!head)
            return 0;
        else if (!head->getNext())
            return head->getVal();
        else
        {
            DubNode* curr = head;
            for (int i = 0; i < length()/2; i++)
                curr = curr->getNext();
            return curr->getVal();
        }
    }
};

int main()
{
    
    DubLinkedList dl;
    int A[] = {8,2,3,9,10,4};
    for (int i = 0; i < 6; i++)
        dl.append(A[i]);
    std::cout << "The middle of dl is " << dl.middle() << std::endl;
    /*int A[] = {8,3,9,6,2};
    CircularLinkedList cl(A,5);
    cl.printList();*/
    /*LinkedList list;
    LinkedList list2;
    int A[] = {2,8,10,15};
    list.insertArray(A,4);
    int B[] = {4,7,12,14};
    list2.insertArray(B,4);
    LinkedList list3 = list.merge(&list2);
    list.printList();
    list2.printList();
    list3.printList();
    list.deleteNode(2);
    list.printList();
    list3.printList();
    if (list3.isLoop())
        std::cout << "It is a loop." << std::endl;
    else
        std::cout << "It is linear." << std::endl;*/
    /*int arr[3] = {3,5,7};
    list.insertArray(arr,3);
    list.printList();
    std::cout << "The length is: " << list.getLen() << std::endl;
    std::cout << "The sum is: " << list.getSum() << std::endl;
    list.insertNodeAfter(2,3);
    list.printListRec();
    std::cout << "The max is: " << list.getMax() << std::endl;
    int x = 7;
    std::cout << "The element " << x << " was found at index " << list.search(x) << std::endl;*/
    return 0;
}