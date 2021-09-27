#include "SparseMatrix.h"
#include <iostream>
#include <math.h>

SparseMatrix::SparseMatrix()
: SparseMatrix(5, 5)
{
    //this->numRows = 5;
    //this->numCols = 5;
}

SparseMatrix::SparseMatrix(int rows, int cols)
: numRows{rows}, numCols{cols}
{
    //this->numRows = rows;
    //this->numCols = cols;
}

SparseMatrix::~SparseMatrix()
{
}

void SparseMatrix::clear()
{
    this->matrix.clear();
}

void SparseMatrix::setSize(int numRows, int numCols)
{
    this->numRows = numRows;
    this->numCols = numCols;
}

int SparseMatrix::getNumRows()
{
    return numRows;
}

int SparseMatrix::getNumCols()
{
    return numCols;
}

void SparseMatrix::addElement(int row, int col, int data)
{
    try
    {
        if (row > this->numRows - 1 || row < 0 || col > this->numCols - 1 || col < 0)
            throw(1);
        bool found = false;
        for (auto &e: matrix)
        {
            if (e.getRow() == row && e.getCol() == col)
            {
                found = true;
                e.setVal(data);
                break;
            }
        }
        if (!found)
            matrix.push_back(Node(row, col, data));
        if (data == 0)
            this->removeElement(row, col);
    }
    catch(int e)
    {
        if (e == 1)
            std::cerr << "The entered row/col data is out of the matrix bounds.add" << std::endl;
    }
}

void SparseMatrix::removeElement(int row, int col)
{
    try 
    {
        if (row > this->numRows - 1 || row < 0 || col > this->numCols - 1 || col < 0)
            throw(1);
        int offset = 0;
        for (auto e: matrix)
        {
            if (row == e.getRow() && col == e.getCol())
            {
                matrix.erase(matrix.begin() + offset);
                break;
            }
            offset++;
        }
    }
    catch (int e)
    {
        if (e == 1)
            std::cerr <<"The entered row/col data is out of the matrix bounds.rem" << std::endl;
    }
}

int SparseMatrix::getElement(int row, int col)
{
    int num = 0;
    try
    {
        if (row > this->numRows - 1 || row < 0 || col > this->numCols - 1 || col < 0)
            throw 1;
        for (auto e: matrix)
            if (row == e.getRow() && col == e.getCol())
            {
                num = e.getVal();
                break;
            }
    }
    catch (int e)
    {
        if (e == 1)
            std::cerr <<"The entered row/col data is out of the matrix bounds.get" << std::endl;
    }
    return num;
}

std::string SparseMatrix::toString()
{
    std::string matString = "";
    std::string space = " ";
    for (auto e: matrix)
    {
        std::string temp = "";
        temp.append(std::to_string(e.getRow()));
        temp.append(" ");
        temp.append(std::to_string(e.getCol()));
        temp.append(" ");
        temp.append(std::to_string(e.getVal()));
        temp.append("\n");
        matString.append(temp);
    }
    return matString;
}

SparseMatrix SparseMatrix::addMatricies(SparseMatrix matrixToAdd)
{
    SparseMatrix newMat(this->getNumRows(), this->getNumCols());
    if (this->getNumRows() == matrixToAdd.getNumRows() && this->getNumCols() == matrixToAdd.getNumCols())
        for (int i = 0; i < this->getNumRows(); i++)
            for (int j = 0; j < this->getNumCols(); j++)
                newMat.addElement(i, j, this->getElement(i, j) + matrixToAdd.getElement(i, j));
    return newMat;
}

SparseMatrix SparseMatrix::multiplyMatricies(SparseMatrix matrixToMult)
{
    SparseMatrix newMat(this->getNumRows(), matrixToMult.getNumCols());
    if (this->getNumCols() == matrixToMult.getNumRows())
        for (int i = 0; i < this->getNumRows(); i++)
            for (int j = 0; j < matrixToMult.getNumCols(); j++)
            {   
                int temp = 0;
                for (int k = 0; k < this->getNumCols(); k++)
                    temp += this->getElement(i, k) * matrixToMult.getElement(k, j);
                newMat.addElement(i, j, temp);
            }
    return newMat;
}

SparseMatrix SparseMatrix::getMinor(int row, int col)
{
    SparseMatrix minor = *this;
    std::vector<Node> newMat;
    for (auto e: minor.matrix)
        if (e.getRow() != row && e.getCol() != col)
           newMat.push_back(Node(e.getRow(), e.getCol(), e.getVal()));
    minor.matrix = newMat;
    for (auto &e: minor.matrix)
    {
        if (e.getRow() > row)
            e.setRow(e.getRow() - 1);
        if (e.getCol() > col)
            e.setCol(e.getCol() - 1);
    }
    minor.setSize(minor.getNumRows() - 1, minor.getNumCols() - 1);
    return minor;
}

/*SparseMatrix SparseMatrix::getMinor(int row, int col) //Ben's method
{
    SparseMatrix minor(this->getNumRows() - 1, this->getNumCols() - 1);
    int r = 0;
    for (int i = 0; i < getNumRows(); i++) 
    {
        if (i == row)
            continue;
        int c = 0;
        for (int j = 0; j < getNumCols(); j++) 
        {
            if (j == col)
                continue;
            minor.addElement(r, c, getElement(i, j));
            c++;
        }
        r++;
    }
    return minor;
}*/

int SparseMatrix::getDet()
{
    int det = 0;
    try
    {
        if (getNumRows() != getNumCols())
            throw(1);
        SparseMatrix cpy = *this;
        if (cpy.getNumRows() == 2)
            det = cpy.getElement(0, 0) * cpy.getElement(1, 1) - cpy.getElement(0, 1) * cpy.getElement(1, 0);
        else
        {
            for (int i = 0; i < cpy.getNumRows(); i++)
                det += pow(-1, i) * cpy.getElement(0, i) * cpy.getMinor(0, i).getDet();
        }
    }
    catch(int e)
    {
        if (e == 1)
            std::cerr << "Matrix isn't even square..." << std::endl;
    }
    return det;
}