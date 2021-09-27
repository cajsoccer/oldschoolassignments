#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <array>
#include <math.h>

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    auto newList = new ListNode((l1->val + l2->val) % 10);
    int carry = (l1->val + l2->val > 9) ? 1 : 0;
    l1 = l1->next;
    l2 = l2->next;
    ListNode* curr = newList;
    while (l1 && l2)
    {
        curr->next = new ListNode((l1->val + l2->val + carry) % 10);
        carry = (l1->val + l2->val + carry > 9) ? 1 : 0;
        l1 = l1->next;
        l2 = l2->next;
        curr = curr->next;
    }
    while (l1)
    {
        curr->next = new ListNode((l1->val + carry) % 10);
        carry = (l1->val + carry > 9) ? 1 : 0;
        l1 = l1->next;
        curr = curr->next;
    }
    while (l2)
    {
        curr->next = new ListNode((l2->val + carry) % 10);
        carry = (l2->val + carry > 9) ? 1 : 0;
        l2 = l2->next;
        curr = curr->next;
    }
    return newList;
}

int fact(int n)
{
    if (n < 0)
        return -1;
    else if (n == 1 || n == 0)
        return 1;
    else
        return n * fact(n-1);
}

int fib(int n)
{
    if (n < 0)
        return - 1;
    else if (n == 1 || n == 0)
        return n;
    else
        return fib(n-1) + fib(n-2);
}

class hashArray
{
private:
    std::array<int,500> arr = {0};
    std::string str;
public:
    hashArray(std::string inputStr = "")
    {
        for (char c: inputStr)
            insert(c);
    }
    int insert(char c)
    {
        if (arr[(int)c] == 0)
        {
            arr[(int)c]++;
            return 1;
        }
        else
        {
            arr[(int)c]++;
            return 2;
        }
    }
    bool del(char c)
    {
        if (arr[(int)c] == 0)
            return false;
        else
        {
            arr[(int)c]--;
            return true;
        }
    }
    int getCount(char c) {return arr[(int)c];}
    void printNonZeros()
    {
        for (int i = 0; i < (int)arr.size(); i++)
            if (arr[int(i)] != 0)
                std::cout << char(i) << ": " << arr[int(i)] << std::endl;
    }
};

void stackFrameCount()
{
    static int stackCount = 1;
    int loc = stackCount;
    std::cout << stackCount++ << std::endl;
    if (stackCount < 5000)
        stackFrameCount();
    if (loc == 1)
        stackCount = 1;
}

int main()
{
    stackFrameCount();
    return 0;
}