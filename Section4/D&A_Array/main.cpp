#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>

class Array
{
public:
    int A[10];
    int size;
    int length;
    void display()
    {
        std::cout << "The current elements are:" << std::endl;
        for (int i = 0; i < length; i++)
            std::cout << i << ": " << A[i] << std::endl;
    }
    void append(int x)
    {
        if (length < size)
        {
            A[length] = x;
            length++;
        }
        else
            std::cout << "The array is full." << std::endl;
    }
    void insert(int index, int x)
    {
        if (index >= 0 && index <= length)
        {
            for (int i = length; i > index; i--)
                A[i] = A[i-1];
            A[index] = x;
            length++;
        }
        else
            std::cout << "Invalid index" << std::endl;
    }
    void del(int index)
    {
        if (index >= 0 && index < length)
        {
            for (int i = index; i < length - 1; i++)
                A[i] = A[i+1];
            length--;
        }
        else
            std::cout << "Invalid index" << std::endl;
    }
    int linSearch(int key)
    {
        for (int i = 0; i < length; i++)
            if (A[i] == key)
                return i;
        return -1;
    }
    int binSearch(int key)
    {
        int start = 0;
        int end = length - 1;
        int mid = (start + end)/2;
        while (true)
        {
            if (mid == start || mid == end)
            {
                if (A[mid] == key)
                    return mid;
                else
                    return -1;
            }
            else if (A[mid] > key)
            {
                end = mid - 1;
                mid = (start + end)/2;
            }
            else if (A[mid] < key)
            {
                start = mid + 1;
                mid = (start + end)/2;
            }
        }
    }
    int get(int index)
    {
        if (index < 0 || index >= length)
            return -1;
        else
            return A[index];
    }
    bool set(int index, int x)
    {
        if (index < 0 || index >= length)
            return false;
        else
        {
            A[index] = x;
            return true;
        }
    }
    int max()
    {
        int max = A[0];
        for (int i = 1; i < length; i++)
            if (A[i] > max)
                max = A[i];
        return max;
    }
    int min()
    {
        int min = A[0];
        for (int i = 1; i < length; i++)
            if (A[i] < min)
                min = A[i];
        return min;
    }
    int sum()
    {
        int sum = 0;
        for (int i = 0; i < length; i++)
            sum += A[i];
        return sum;
    }
    double avg()
    {
        return (double)sum()/length;
    }
    void reverse()
    {
        int temp = 0;
        for (int i = 0; i < length/2; i++)
        {
            temp = A[i];
            A[i] = A[length - 1 - i];
            A[length - 1 - i] = temp;
        }
    }
    bool isSorted()
    {
        bool sorted = true;
        for (int i = 0; i < length - 1; i++)
            if (A[i] > A[i+1])
                sorted = false;
        return sorted;
    }
};

Array mergeArrays(const Array &arr1, const Array &arr2)
{
    Array newArr = {{0}, arr1.size + arr2.size, arr1.length + arr2.length};
    int j = 0;
    int k = 0;
    for (int i = 0; i < arr1.length + arr2.length; i++)
        if (j == arr1.length && k != arr2.length)
        {
            newArr.A[i] = arr2.A[k];
            k++;
        }
        else if (k == arr2.length && j != arr1.length)
        {
            newArr.A[i] = arr1.A[j];
            j++;
        }
        else
        {
            if (arr1.A[j] <= arr2.A[k])
            {
                newArr.A[i] = arr1.A[j];
                j++;
            }
            else
            {
                newArr.A[i] = arr2.A[k];
                k++;
            }
        }
    return newArr;
}

int singleMissingSorted(int* arr, int size)
{
    for (int i = 0; i < size - 1; i++)
        if (arr[i+1] - arr[i] != 1)
            return arr[i] + 1;
    return -1;
}

std::vector<int> multipleMissingSorted(int* arr, int size)
{
    std::vector<int> missingElements;
    int temp = 0;
    for (int i = 0; i < size - 1; i++)
        if (arr[i+1] - arr[i] != 1)
        {   
            temp = arr[i];
            while (temp < arr[i+1] - 1)
            {
                missingElements.push_back(temp + 1);
                temp++;
            }
        }
    return missingElements;
}

std::vector<int> multipleMissingUnsorted(int* arr, int size)
{
    std::vector<int> missingElems;
    int low = arr[0];
    int high = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > high)
            high = arr[i];
        if (arr[i] < low)
            low = arr[i];
    }
    for (int i = low; i < high; i++)
    {
        bool found = false;
        for (int j = 0; j < size; j++)
            if (arr[j] == i)
                found = true;
        if (!found)
            missingElems.push_back(i);
    }
    return missingElems;
}

std::vector<int> duplicatesSorted(int* arr, int size)
{
    std::vector<int> dups;
    for (int i = 1; i < size; i++)
        if (arr[i] == arr[i-1] && std::find(dups.begin(), dups.end(), arr[i]) == dups.end())
            dups.push_back(arr[i]);
    return dups;
}

int* duplicatesHash(int* arr, int size)
{
    int max = arr[0];
    for (int i = 1; i < size; i++)
        if (arr[i] > max)
            max = arr[i];
    int* dups = new int[max + 1];
    for (int i = 0; i <= max; i++)
        dups[i] = 0;
    for (int i = 0; i < size; i++)
        dups[arr[i]]++;
    return dups;
}

void pairFind(int* arr, int size, int val, int &a, int &b)
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (i != j && arr[i] + arr[j] == val)
            {
                a = arr[i];
                b = arr[j];
                j = size;
                i = size;
            }
}

void maxMinSingle(int *arr, int size, int &max, int &min)
{
    max = arr[0];
    min = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
            max = arr[i];
        else if (arr[i] < min)
            min = arr[i];
    }
}

int main()
{
    /*int arr[11] = {6,7,8,9,10,11,13,14,15,16,17};
    std::cout << singleMissingSorted(arr, 11) << std::endl;*/
    /*int arr[11] = {6,7,8,9,11,12,15,16,17,18,19};
    std::vector<int> missingElements = multipleMissingSorted(arr, 11);
    for (auto e: missingElements)
        std::cout << e << std::endl;*/
    /*int arr[10] = {3,7,4,9,12,6,1,11,2,10};
    std::vector<int> missingElems = multipleMissingUnsorted(arr, 10);
    for (auto e: missingElems)
        std::cout << e << std::endl;*/
    /*int arr[10] = {3,6,8,8,10,12,15,15,15,20};
    int arr2[10] = {8,3,6,4,6,5,6,8,2,7};
    std::vector<int> dups = duplicatesSorted(arr, 10);
    for (auto e: dups)
        std::cout << e << std::endl;
    int* dups2 = duplicatesHash(arr2, 10);
    for (int i = 0; i < 9; i++)
        if (dups2[i] > 1)
            std::cout << i << " appears " << dups2[i] << " number of times." << std::endl;*/
    int arr[10] = {6,3,8,10,16,7,5,2,9,14};
    int a = 0;
    int b = 0;
    pairFind(arr, 10, 10, a, b);
    std::cout << a << " " << b << std::endl;
    int max = 0;
    int min = 0;
    maxMinSingle(arr, 10, max, min);
    std::cout << "Max: " << max << " Min: " << min << std::endl;
    return 0;
}