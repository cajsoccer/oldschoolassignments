#include <iostream>
#include <LinkedList.h>

int main()
{
    LinkedList *memList = new LinkedList();
    int algoSel = 0;
    std::cout << "Please select an algorithm for adding programs:" << std::endl;
    std::cout << "1. First fit" << std::endl;
    std::cout << "2. Worst fit" << std::endl;
    std::cout << "3. Best fit" << std::endl;
    std::cin >> algoSel;
    while (algoSel < 1 || algoSel > 3)
    {
        std::cout <<"Invalid selection. Enter an integer from 1-3." << std::endl;
        std::cin >> algoSel;
    }
    int input = 0;
    while (input != 5)
    {
        std::cout << "1. Add program" << std::endl;
        std::cout << "2. Kill program" << std::endl;
        std::cout << "3. Fragmentation" << std::endl;
        std::cout << "4. Print memory" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Enter your input: ";
        std::cin >> input;
        if (input == 1)
        {
            std::string name = "";
            int size = 0;
            int blockSize = 0;
            int *failRet = new int;
            std::cout << "Enter the name of the program to add: ";
            std::cin >> name;
            std::cout << "Enter the size of " + name + ":";
            std::cin >> size;
            blockSize = size / 4;
            if ( size % 4 != 0)
                blockSize++;
            if (memList->insertProgHandler(name, blockSize, failRet, algoSel))
                std::cout << name << " succesfully added." << std::endl;
            else
            {
                if (*failRet == 1)
                    std::cout << name << " could not be added. It already exists." << std::endl;
                else if (*failRet == 2)
                    std::cout << name << " could not be added. There isn't enough room." << std::endl;
            }
            delete failRet;
        }
        else if (input == 2)
        {
            std::string name = "";
            int size = 0;
            std::cout << "Enter the name of the program to kill: ";
            std::cin >> name;
            if (memList->killProg(name, size))
                std::cout << name << " has been deleted. " << size << " pages were freed." << std::endl;
            else
                std::cout << name << " was not found." << std::endl;
        }
        else if (input == 3)
            std::cout << "The number of fragments is: " << memList->getFrags() << std::endl;
        else if (input == 4)
            memList->printNodes();
        else if (input == 5)
            std::cout << "Goodbye, lad." << std::endl;
        else 
            std::cout << "Invalid input." << std::endl;
    }
    return 0;
}