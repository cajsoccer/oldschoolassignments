#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>


enum SortType {SELECTION, MERGE};

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

bool createRandFile(int size)
{
    std::ofstream file {std::to_string(size) + "_rand.txt"};
    if (file.is_open())
    {
        for (int i = 0; i < size; i++)
            file << std::to_string(rand() % 100 + 1) + "\n";
        file.close();
        return true;
    }
    else
        return false;
}

bool loadRandFile(std::string name, int size, std::vector<int*> &vec)
{
    std::ifstream file {name};
    if (file.is_open())
    {
        int* A = new int[size];
        std::string line = "";
        int i = 0;
        while (getline(file,line))
            A[i++] = std::stoi(line);
        vec.push_back(A);
        file.close();
        return true;
    }
    else
        return false;
}

bool saveSortedFile(int* A, int size)
{
    std::ofstream file {std::to_string(size) + "_sorted.txt"};
    if (file.is_open())
    {
        for (int i = 0; i < size; i++)
            file << std::to_string(A[i]) + "\n";
        file.close();
        return true;
    }
    else
        return false;
}

int sortAndMeasureTime(int* A, int size, SortType s)
{
    clock_t startTime = clock();
    if (s == SELECTION)
        selectionSort(A, size);
    else if (s == MERGE)
        mergeSort(A,0,size-1);
    else
        return -1;
    clock_t endTime = clock() - startTime;
    saveSortedFile(A,size);
    return endTime;
}

int main()
{
    createRandFile(5000);
    createRandFile(10000);
    createRandFile(20000);
    createRandFile(50000);
    std::vector<int*> unsortedLists;
    loadRandFile("5000_rand.txt",5000,unsortedLists);
    loadRandFile("10000_rand.txt",10000,unsortedLists);
    loadRandFile("20000_rand.txt",20000,unsortedLists);
    loadRandFile("50000_rand.txt",50000,unsortedLists);
    std::cout << "Time to sort 5000: " << sortAndMeasureTime(unsortedLists[0],5000,MERGE) << std::endl;
    std::cout << "Time to sort 10000: " << sortAndMeasureTime(unsortedLists[1],10000,MERGE) << std::endl;
    std::cout << "Time to sort 20000: " << sortAndMeasureTime(unsortedLists[2],20000,MERGE) << std::endl;
    std::cout << "Time to sort 50000: " << sortAndMeasureTime(unsortedLists[3],50000,MERGE) << std::endl;
    /*std::cout << "Time to sort 5000: " << sortAndMeasureTime(unsortedLists[0],5000,SELECTION) << std::endl;
    std::cout << "Time to sort 10000: " << sortAndMeasureTime(unsortedLists[1],10000,SELECTION) << std::endl;
    std::cout << "Time to sort 20000: " << sortAndMeasureTime(unsortedLists[2],20000,SELECTION) << std::endl;
    std::cout << "Time to sort 50000: " << sortAndMeasureTime(unsortedLists[3],50000,SELECTION) << std::endl*/;
    return 0;
}