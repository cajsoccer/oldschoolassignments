#include <iostream>
#include <Pokedex.h>

int main()
{
    int size = 0;
    std::cout << "Welcome to the Pokedex. Please enter the size of the Pokedex:";
    std::cin >> size;
    Pokedex *list = new Pokedex(size);
    int choice = 0;
    while (choice != 5)
    {
        std::cout << "Please select an option:" << std::endl;
        std::cout << "1. List Pokemon" << std::endl;
        std::cout << "2. Add Pokemon" << std::endl;
        std::cout << "3. Check a Pokemon's Stats" << std::endl;
        std::cout << "4. Sort Pokemon" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cin >> choice;
        if (choice == 1)
        {
            std::vector <std::string> retVec = list->listPokemon();
            if (retVec.empty())
                std::cout << "The list is currently empty." << std::endl;
            else
                for (int i = 0; i < retVec.size(); i++)
                    std::cout << i + 1 << ". " << retVec.at(i) << std::endl;
        }
        else if (choice == 2)
        {
            std::string insertPokemon = "";
            std::cout << "Enter the name of the Pokemon you wish to add to the list:";
            std::cin >> insertPokemon;
            int result = list->addPokemon(insertPokemon);
            if (result == 0)
                std::cout << insertPokemon << " successfully added to the list." << std::endl;
            else if (result == 1)
                std::cout << "The list is full." << std::endl;
            else if (result == 2)
                std::cout << insertPokemon << " is already in the list." << std::endl;
        }
        else if (choice == 3)
        {
            std::string checkPokemon = "";
            std::cout << "Enter the name of the Pokemon you want the stats of:"; 
            std::cin >> checkPokemon;
            std::vector <int> stats = list->checkStats(checkPokemon);
            if (stats.empty())
                std::cout << checkPokemon << " was not found within the list." << std::endl;
            else
            {
                std::cout << "The stats for " << checkPokemon << " are:\nAttack: " << stats.at(0) << "\nDefense: " << stats.at(1) << "\nSpeed: " << stats.at(2) << std::endl;
            }
        }
        else if (choice == 4)
        {
            list->sortPokemon();
            std::cout << "List sorted." << std::endl;
        }
        else if (choice == 5)
            std::cout << "Goodbye." << std::endl;
        else
            std::cout << "Invalid selection." << std::endl;
    }
    delete list;
    return 0;
}