#ifndef POKEDEX_H
#define POKEDEX_H
#include <vector>
#include <Pokemon.h>

class Pokedex
{
private: 
    std::vector <Pokemon> list;
    int size;
    int curr;
public:
    Pokedex(int sizeInput);
    ~Pokedex();
    std::vector <std::string> listPokemon();
    int addPokemon(std::string spec);
    std::vector <int> checkStats(std::string spec);
    void sortPokemon();
};

#endif // POKEDEX_H
