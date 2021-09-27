#ifndef SQUARE_H
#define SQUARE_H

class Square
{
private: 
    static int start;
    int **col;
    int size;
public:
    Square(const int &size);
    ~Square();
    void printSquare();
    void printRowSums();
    void printColSums();
    void printDiagSums();
};

#endif // SQUARE_H
