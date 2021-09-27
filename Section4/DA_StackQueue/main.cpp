#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <array>
#include <math.h>

class Frame
{
private:
    int val;
    Frame* next;
    Frame* prev;
public:
    Frame()
    {
        next = nullptr;
        prev = nullptr;
    }
    Frame(int v)
    {
        next = nullptr;
        prev = nullptr;
        val = v;
    }
    int getVal(){return val;}
    Frame* getNext(){return next;}
    Frame* getPrev(){return prev;}
    void setNext(Frame* n){next = n;}
    void setPrev(Frame* p){prev = p;}
};

class Stack
{
private:
    Frame* bottom;
    Frame* top;
public:
    Stack()
    {
        bottom = nullptr;
        top = nullptr;
    }
    ~Stack()
    {
        while (bottom)
            pop();
    }
    void push(int x)
    {
        Frame* newFrame = new Frame(x);
        if (!bottom)
        {
            bottom = newFrame;
            top = newFrame;
        }
        else
        {
            top->setNext(newFrame);
            newFrame->setPrev(top);
            top = newFrame;
        }
    }
    bool pop()
    {
        if (!bottom)
            return false;
        else if (bottom == top)
        {
            delete bottom;
            bottom = nullptr;
            top = nullptr;
            return true;
        }
        else
        {
            Frame* temp = top;
            top = top->getPrev();
            delete temp;
            return true;
        }
    }
    bool isEmpty()
    {
        if (!bottom)
            return true;
        else 
            return false;
    }
    char peek()
    {
        if (top)
            return top->getVal();
        else
            return 0;
    }
    void print()
    {
        std::cout << "The contents of the stack are: ";
        Frame* curr = top;
        while (curr)
        {
            std::cout << curr->getVal() << " ";
            curr = curr->getPrev();
        }
        std::cout << std::endl;
    }
};

bool isBal(std::string s)
{
    Stack pCounter;
    for (int i = 0; i < (int)s.length(); i++)
    {
        if (s[i] == '(')
            pCounter.push(s[i]);
        else if (s[i] == ')')
            if (!pCounter.pop())
                return false;
    }
    if (!pCounter.isEmpty())
        return false;
    else
        return true;
}

bool isBal3(std::string s)
{
    Stack pCounter;
    for (int i = 0; i < (int)s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            pCounter.push(s[i]);
        else
        {
            if (s[i] == ')')
            {
                if (pCounter.peek() != '(')
                    return false;
                else if (!pCounter.pop())
                    return false;
            }
            else if (s[i] == '}')
            {
                if (pCounter.peek() != '{')
                    return false;
                else if (!pCounter.pop())
                    return false;
            }
            else if (s[i] == ']')
            {
                if (pCounter.peek() != '[')
                    return false;
                else if (!pCounter.pop())
                    return false;
            }
        }
    }
    if (pCounter.isEmpty())
        return true;
    else
        return false;
}

bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return true;
    else 
        return false;
}

int getPrec(char c)
{
    if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return 0;
}

std::string infixToPostfix(std::string s)
{
    std::string ns = "";
    Stack stk;
    for (int i = 0; i < (int)s.length(); i++)
    {
        if (!isOperator(s[i]))
            ns += s[i];
        else
        {
            while (!stk.isEmpty())
            {
                if (getPrec(s[i]) > getPrec(stk.peek()))
                {
                    stk.push(s[i]);
                    break;
                }
                else
                {
                    ns += stk.peek();
                    stk.pop();
                }
            }
            if (stk.isEmpty())
                stk.push(s[i]);
        }
    }
    while (!stk.isEmpty())
    {
        ns += stk.peek();
        stk.pop();
    }
    return ns;
}

class Queue
{
    Frame* front;
    Frame* end;
public:
    Queue()
    {
        front = nullptr;
        end = nullptr;
    }
    ~Queue()
    {
        while(front)
        {
            Frame* temp = front;
            front = front->getNext();
            delete temp;
        }
    }
    void push(int x)
    {
        Frame* newFrame = new Frame(x);
        if (!end)
        {
            front = newFrame;
            end = newFrame;
        }
        else
        {
            newFrame->setNext(front);
            front->setPrev(newFrame);
            front = newFrame;
        }
    }
    bool pop()
    {
        if (!end)
            return false;
        Frame* temp = end;
        if (front == end)
        {
            delete temp;
            front = nullptr;
            end = nullptr;
        }
        else
        {
            end->getPrev()->setNext(nullptr);
            end = end->getPrev();
            delete temp;
        }
        return true;
    }
    bool isEmpty()
    {
        if (!end)
            return true;
        else
            return false;
    }
    int first()
    {
        return end->getVal();
    }
    int last()
    {
        return front->getVal();
    }
    void print()
    {
        Frame* curr = front;
        while (curr)
        {
            std::cout << curr->getVal() << " ";
            curr = curr->getNext();
        }
        std::cout << std::endl;
    }
};

int main()
{
    /*std::string p = "a+b*c-d/e";
    std::string p2 = "a+b*c";
    std::string p3 = "35*62/+4-";
    std::cout << infixToPostfix(p2) << std::endl;*/
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.print();
    q.pop();
    q.print();
    std::cout << q.isEmpty() << std::endl;
    q.pop();
    q.pop();
    std::cout << q.isEmpty() << std::endl;
    return 0;
}