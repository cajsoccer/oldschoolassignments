#ifndef SPARSEMATRIX_H
#define SPARSEMATRIX_H
#include <Node.h>
#include <vector>
#include <string>

class SparseMatrix
{
private:
    int numRows;
    int numCols;
    std::vector<Node> matrix;
public:
    SparseMatrix();
    SparseMatrix(int rows, int cols);
    ~SparseMatrix();
    void clear();
    void setSize(int numRows, int numCols);
    int getNumRows();
    int getNumCols();
    void addElement(int row, int col, int data);
    void removeElement(int row, int col);
    int getElement(int row, int col);
    std::string toString();
    SparseMatrix addMatricies(SparseMatrix matrixToAdd);
    SparseMatrix multiplyMatricies(SparseMatrix matrixToAdd);
    SparseMatrix getMinor(int row, int col);
    int getDet();
};

#endif // SPARSEMATRIX_H
