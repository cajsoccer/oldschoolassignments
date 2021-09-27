#include <iostream>

void printArray(int* A, int size)
{
    for (int i = 0; i < size; i ++)
        std::cout << A[i] << " ";
    std::cout << std::endl;
}

void bubbleSort(int* A, int size)
{
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (A[j] > A[j+1])
                std::swap(A[j], A[j+1]);
}

void insertionSort(int* A, int size)
{
    int temp = 0;
    int temp2 = 0;
    for (int i = 1; i < size; i++)
    {
        bool inserted = false;
        for (int j = 0; j < i; j++)
        {
            if (A[i] < A[j] && !inserted)
            {
                temp = A[j];
                A[j] = A[i];
                inserted = true;
            }
            if (inserted)
            {
                temp2 = A[j+1];
                A[j+1] = temp;
                temp = temp2;
            }
        }
    }
}

void selectionSort(int* A, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min = A[i];
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (A[j] < min)
            {
                minIndex = j;
                min = A[j];
            }
        }
        if (minIndex != i)
            std::swap(A[i], A[minIndex]);
    }
}

void merge(int* A, int l, int m, int h)
{
    int* B = new int[h+1];
    int i = l;
    int j = m+1;
    int k = l;
    while (i <= m && j <= h)
    {
        if (A[i] < A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }
    while (i <= m)
        B[k++] = A[i++];
    while (j <= h)
        B[k++] = A[j++];
    for (int i = l; i <= h; i++)
        A[i] = B[i];
}

void mergeSort(int* A, int l, int h)
{
    if (l == h)
        return;
    else
    {
        int m = (l + h) / 2;
        mergeSort(A,l,m);
        mergeSort(A,m+1,h);
        merge(A,l,m,h);
    }
}

void countSort(int* A, int size)
{
    int max = A[0];
    for (int i = 1; i < size; i++)
        if (A[i] > max)
            max = A[i];
    int B[max + 1];
    for (int i = 0; i <= max; i++)
        B[i] = 0;
    for (int i = 0; i < size; i++)
        B[A[i]]++;
    for (int i = 0, j = 0; i <= max; i++)
        while (B[i]-- > 0)
            A[j++] = i;
}

int main()
{
    int arr[] = {11,13,7,12,16,9,24,5,10,3};
    //int arr[] = {6,3,9,10,15,6,8,12,3,6};
    printArray(arr,10);
    countSort(arr,10);
    printArray(arr,10);
    return 0;
}