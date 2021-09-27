#include "Pokedex.h"

bool iequals(const std::string& a, const std::string& b)
{
    return std::equal(a.begin(), a.end(),
                      b.begin(), b.end(),
                      [](char a, char b) {
                          return tolower(a) == tolower(b);
                      });
}

Pokedex::Pokedex(int sizeInput)
{
    size = sizeInput;
    curr = 0;
}

Pokedex::~Pokedex()
{
}

std::vector <std::string> Pokedex::listPokemon()
{
    std::vector <std::string> nameVec;
    for (auto pokemon: list)
        nameVec.push_back(pokemon.getSpecies());
    return nameVec;
}

int Pokedex::addPokemon(std::string spec)
{
    int canAdd = 0;
    if (curr >= size)
        canAdd = 1;
    else for (auto pokemon: list)
        if (iequals(pokemon.getSpecies(), spec))
            canAdd = 2;
    if (canAdd == 0)
    {
        list.push_back(Pokemon(spec));
        curr++;
    }
    return canAdd;
}

std::vector <int> Pokedex::checkStats(std::string spec)
{
    std::vector <int> statVec;
    for (auto pokemon: list)
    {
        if (pokemon.getSpecies() == spec)
        {
            statVec.push_back(pokemon.getAttack());
            statVec.push_back(pokemon.getDefense());
            statVec.push_back(pokemon.getSpeed());
        }
    }
    return statVec;
}

void Pokedex::sortPokemon()
{
    for (int i = 0; i < list.size() - 1; i++)
    {
        int jMin = i;
        for (int j = i + 1; j < list.size(); j++)
        {
            std::string temp1 = list.at(j).getSpecies();
            for (int k = 0; k < temp1.length(); k++)
                temp1[k] = tolower(temp1[k]);
            std::string temp2 = list.at(jMin).getSpecies();
            for (int k = 0; k < temp2.length(); k++)
                temp2[k] = tolower(temp2[k]);
            if (temp1 < temp2)
                jMin = j;
        }
    if (jMin != i)
        std::swap(list.at(i), list.at(jMin));
    }
}
