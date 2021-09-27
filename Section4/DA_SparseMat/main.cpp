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
    int row;
    int col;
    int val;
public:
    Node()
    {
        row = 0;
        col = 0;
        val = 0;
    }
    Node(int row, int col, int val)
    {
        this->row = row;
        this->col = col;
        this->val = val;
    }
    int getRow(){return row;}
    int getCol(){return col;}
    int getVal(){return val;}
};

class SparseMatrix
{
private:
    std::vector<Node> mat;
    int maxRow;
    int maxCol;
public:
    SparseMatrix()
    {
        maxRow = 5;
        maxCol = 5;
    }
    SparseMatrix(int row, int col)
    {
        maxRow = row;
        maxCol = col;
    }
    bool addElem(int row, int col, int val)
    {
        if (col > maxCol || col < 1 || row > maxRow || row < 1 || val == 0)
            return false;
        for (auto e: mat)
            if ((e.getCol() == col && e.getRow() == row))
                return false;
        mat.push_back(Node(row, col, val));
        return true;
    }
    int getElem(int row, int col)
    {
        int val = 0;
        for (auto e: mat)
            if (e.getCol() == col && e.getRow() == row)
                val = e.getVal();
        return val;
    }
    void printNonZeros()
    {
        for (auto e: mat)
            std::cout << "row: " << e.getRow() << " col: " << e.getCol() << " val: " << e.getVal() << std::endl;
    }
    void printMatrix()
    {
        for (int i = 1; i <= maxRow; i++)
        {
            for (int j = 1; j <= maxCol; j++)
                std::cout << getElem(i, j) << " ";
            std::cout << std::endl;
        }
    }
    int getMaxRow(){return maxRow;}
    int getMaxCol(){return maxCol;}
    SparseMatrix addMatrices(SparseMatrix mat2)
    {
        SparseMatrix newMat(maxRow, maxCol);
        if (maxRow != mat2.getMaxRow() || maxCol != mat2.getMaxCol())
            return newMat;
        for (int i = 1; i <= maxRow; i++)
        {
            for (int j = 1; j <= maxCol; j++)
            {
                if (getElem(i, j) != 0 && mat2.getElem(i, j) != 0)
                    newMat.addElem(i, j, getElem(i,j) + mat2.getElem(i,j));
                else if (getElem(i,j) != 0)
                    newMat.addElem(i, j, getElem(i,j));
                else if (mat2.getElem(i,j) != 0)
                    newMat.addElem(i,j, mat2.getElem(i,j));
            }
        }
        return newMat;
    }
};

class PolyTerm
{
private:
    int degree;
    int constant;
public:
    int getDegree(){return degree;}
    int getConstant(){return constant;}
    PolyTerm()
    {
        degree = 0;
        constant = 0;
    }
    PolyTerm(int degree, int constant)
    {
        this->degree = degree;
        this->constant = constant;
    }
};

class PolyList
{
private: 
    std::vector<PolyTerm> list;
public:
    PolyList(){}
    bool insertElement(int degree, int constant)
    {
        for (auto e: list)
            if (e.getDegree() == degree)
                return false;
        list.push_back(PolyTerm(degree, constant));
        return true;
    }
    int getElement(int degree)
    {
        int val = 0;
        for (auto e: list)
            if (e.getDegree() == degree)
                val = e.getConstant();
        return val;
    }
    double functionCall(double x)
    {
        double sum = 0.0;
        for (auto e: list)
            sum += e.getConstant() * pow(x, e.getDegree());
        return sum;
    }
    std::vector<PolyTerm> getList(){return list;}
    void printList()
    {
        for (auto e: list)
            std::cout << "degree: " << e.getDegree() << " constant: " << e.getConstant() << std::endl;
        std::cout << std::endl;
    }
    void printFullList()
    {
        int minDeg = list[0].getDegree();
        int maxDeg = list[0].getDegree();
        for (auto e: list)
        {
            if (e.getDegree() > maxDeg)
                maxDeg = e.getDegree();
            if (e.getDegree() < minDeg)
                minDeg = e.getDegree();
        }
        while (maxDeg >= minDeg)
        {
            if (getElement(maxDeg) != 0)
            {
                if (maxDeg != -1 && maxDeg != 0 && maxDeg != 1)
                    std::cout << getElement(maxDeg) << "x^" << maxDeg;
                else if (maxDeg == -1 || maxDeg == 1)
                    std::cout << getElement(maxDeg) << "x";
                else
                    std::cout << getElement(maxDeg);
                if (maxDeg > minDeg)
                    std::cout << " + ";
            }
            maxDeg--;
        }
        std::cout << std::endl;
    }
    PolyList addLists(PolyList l2)
    {
        PolyList newlist;
        for (auto e: list)
        {
            if (l2.getElement(e.getDegree() != 0))
                newlist.insertElement(e.getDegree(), e.getConstant() + l2.getElement(e.getDegree()));
            else
                newlist.insertElement(e.getDegree(), e.getConstant());
        }
        for (auto e: l2.getList())
            if (this->getElement(e.getDegree() == 0))
                newlist.insertElement(e.getDegree(), e.getConstant());
        return newlist;
    }
};

int main()
{
    /*SparseMatrix mat1(5,5);
    mat1.addElem(1,4,6);
    mat1.addElem(2,2,7);
    mat1.addElem(3,2,2);
    mat1.addElem(3,4,5);
    mat1.addElem(5,1,4);
    mat1.printMatrix();
    std::cout << std::endl;
    SparseMatrix mat2(5,5);
    mat2.addElem(2,2,3);
    mat2.addElem(2,5,5);
    mat2.addElem(3,3,2);
    mat2.addElem(3,5,7);
    mat2.addElem(4,4,9);
    mat2.addElem(5,1,8);
    mat2.printMatrix();
    std::cout << std::endl;
    SparseMatrix mat3 = mat1.addMatrices(mat2);
    mat3.printMatrix();*/
    /*SparseMatrix m1(4,5);
    m1.addElem(2,1,4);
    m1.addElem(1,3,3);
    m1.addElem(2,5,7);
    m1.addElem(3,3,5);
    m1.addElem(3,5,8);
    m1.addElem(4,2,6);
    m1.printMatrix();
    std::cout << std::endl;
    SparseMatrix m2(4,5);
    m2.addElem(1,5,2);
    m2.addElem(2,2,5);
    m2.addElem(2,5,6);
    m2.addElem(3,1,4);
    m2.addElem(3,3,8);
    m2.addElem(4,5,9);
    m2.printMatrix();
    std::cout << std::endl;
    SparseMatrix m3 = m1.addMatrices(m2);
    m3.printMatrix();*/
    PolyList p1;
    p1.insertElement(4,5);
    p1.insertElement(2,2);
    p1.insertElement(0,5);
    p1.printFullList();
    PolyList p2;
    p2.insertElement(4,6);
    p2.insertElement(3,5);
    p2.insertElement(2,9);
    p2.insertElement(1,2);
    p2.insertElement(0,3);
    p2.printFullList();
    PolyList p3 = p1.addLists(p2);
    p3.printFullList();
    PolyList p4;
    p4.insertElement(3,4);
    p4.insertElement(2,9);
    p4.insertElement(1,6);
    p4.insertElement(0,7);
    std::cout << p4.functionCall(2.0) << std::endl;
    return 0;
}