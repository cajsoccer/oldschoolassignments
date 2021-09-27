#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <array>

int sumRec(int n)
{
    if (n == 0)
        return 0;
    else 
        return sumRec(n-1) + n;
}

class Matrix
{
private: 
    int* mat;
    int size;
public:
    Matrix();
    Matrix(int size);
    ~Matrix();
    void set(int i, int j, int x);
    int get(int i, int j);
    void print();
};

Matrix::Matrix()
{
    size = 5;
    mat = new int[15];
}

Matrix::Matrix(int size)
{
    this->size = size;
    mat = new int[sumRec(size)];
}

Matrix::~Matrix()
{
    delete []mat;
}

void Matrix::set(int i, int j, int x)
{
    if (j <= i && i >= 1 && i <= size && j >= 1 && j <= size)
        mat[sumRec(i-1) + j - 1] = x;
}

int Matrix::get(int i, int j)
{
    if (j <= i && i >= 1 && i <= size && j >= 1 && j <= size)
        return mat[sumRec(i-1) + j - 1];
    else
        return 0;
}

void Matrix::print()
{
    for (int i = 1; i <= size; i++)
    {
        for (int j = 1; j <= size; j++)
        {
            if (j <= i)
                std::cout << mat[sumRec(i-1) + j - 1] << " ";
            else
                std::cout << 0 << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    /*Matrix mat(5);
    for (int i = 1; i <= 5; i++)
        for (int j = 1; j <=5; j++)
            mat.set(i, j, i+j);
    mat.print();
    std::cout << mat.get(1,1) << std::endl;
    std::cout << mat.get(2,2) << std::endl;*/
    std::array<std::array<int,5>,5> mat;
    for (int i = 0; i < (int)mat.size(); i++)
        for (int j = 0; j < (int)mat.size(); j++)
        {
                if (j >=i)
                    mat[i][j] = i + 2;
                else
                    mat[i][j] = j + 2;
        }
    for (int i = 0; i < (int)mat.size(); i++)
    {
        for (int j = 0; j < (int)mat.size(); j++)
            std::cout << mat[i][j] << " ";
        std::cout << std::endl;
    }
    return 0;
}