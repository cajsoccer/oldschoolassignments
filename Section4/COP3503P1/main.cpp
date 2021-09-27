#include <iostream>
#include <Square.h>
#include <vector>

int main()
{
    int size = 0;
    std::cout << "Enter an odd number between 3 and 15 for your squares:";
    std::cin >> size;
    while (size % 2 != 1 || size < 3 || size > 15)
    {
        std::cout << "Invalid input, enter another number:";
        std::cin >> size;
    }
    std::vector <Square*> squareList;
    for (int i = 0; i < 4; i++)
    {
        Square *tempSquare = new Square(size);
        squareList.push_back(tempSquare);
    }
    int count = 1;
    for (auto s: squareList)
    {
        std::cout << "Information for square #" << count  << ":" << std::endl;
        s->printSquare();
        s->printRowSums();
        s->printColSums();
        s->printDiagSums();
        std::cout << std::endl;
        count++;
    }
    return 0;
}