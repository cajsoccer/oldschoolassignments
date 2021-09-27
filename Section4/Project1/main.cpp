#include <iostream>
#include <string> 
#include <vector>

using namespace std;

int *apply_all(const int *array1, const int *array2, int size1, int size2);
void print_array(const int *array, int size);

int main()
{
    int array1 [] {1,2,3,4,5};
    int array2 [] {10,20,30};
    int *new_array = apply_all(array1, array2, 5, 3);
    print_array(new_array, 15);
    return 0;
}

int *apply_all(const int *array1, const int *array2, int size1, int size2)
{
    int newSize = size1*size2;
    int *new_array = new int[newSize];
    int count {0};
    for (int i {0}; i < size2; i++)
    {
        for (int j {0}; j < size1; j++)
        {
            new_array[count] = array1[j] * array2[i];
            count++;
        }
    }
    return new_array;
}

void print_array(const int *array, int size)
{
    for (int i {0}; i < size; i++)
    {
        cout << array[i]/* *(array + i) */ << " " << endl;
    }
}