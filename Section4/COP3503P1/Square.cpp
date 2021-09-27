#include "Square.h"
#include <string>
#include <iostream>

int Square::start = 1;

Square::Square(const int &inSize)
{
    col = new int*[size];
    size = inSize;
    for (int i = 0; i < size; i++) //Initialize pointers in col's array to arrays of ints.
    {
        col[i] = new int[size];
    }
    for (int i = 0; i < size; i++) //Initialize the values of each row array to 0.
    {
        for (int j = 0; j < size; j++)
        {
            col[i][j] = 0;
        }
    }
    int xPos = size/2;
    int yPos = 0; 
    int val = Square::start;
    for (int i = 0; i < size * size; i++) //Implement Siamese Method
    {
            int xPosTemp = xPos;
            int yPosTemp = yPos;
            col[yPos][xPos] = val;
            val++;
            if (yPos == 0)
                yPosTemp = size -1;
            else
                yPosTemp--;
            if (xPos == size - 1)
                xPosTemp = 0;
            else
                xPosTemp++;
            if (col[yPosTemp][xPosTemp] != 0)
            {
                if (yPos == size -1)
                    yPos = 0;
                else
                    yPos++;
            }
            else
            {
                xPos = xPosTemp;
                yPos = yPosTemp;
            }
    }
    Square::start++;
}

Square::~Square()
{
    for (int i = 0; i < size; i++)
    {
        delete[] col[i];
    }
    delete[] col;
}

void Square::printSquare()
{
    for (int i = 0; i < size; i++) //Prints each value of the matrix.
    {
        for (int j = 0; j < size; j++)
        {
            std::string space = "";
            if (col[i][j] < 10)
                space = "  ";
            else 
                space = " ";
            std::cout << col[i][j] << space;
        }
        std::cout << "" <<std::endl;
    }        
}
void Square::printRowSums()
{
    std::cout << "The values for the rows are: ";
    for (int i = 0; i < size; i++) //Prints sum of each row.
    {
        int sum = 0;
        for (int j = 0; j < size; j++)
        {
            sum += col[j][i];
        }
    std::cout << sum << " ";
    }
    std::cout << std::endl;
}
void Square::printColSums()
{
    std::cout << "The values for the columns are: ";
    for (int i = 0; i < size; i++) //Prints sum of each column.
    {
        int sum = 0;
        for (int j = 0; j < size; j++)
        {
            sum += col[i][j];
        }
        std::cout << sum << " ";
    }
    std::cout << std::endl;
}
void Square::printDiagSums()
{
    std::cout << "The values for the diagonals are: ";
    int diag1 = 0;
    int diag2 = 0;
    for (int i = 0; i < size; i++) //Prints sum of each diagonal.
    {
        for (int j = 0; j < size; j++)
        {
            if (i == j)
                diag1 += col[j][i];
            if (i + j == size -1)
                diag2 += col[j][i];
        }
    }
    std:: cout << diag1 << " " << diag2 << std::endl;
}