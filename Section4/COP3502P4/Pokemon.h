#ifndef POKEMON_H
#define POKEMON_H
#include <string>

class Pokemon
{
private: 
    std::string species;
    int attack;
    int defense;
    int speed;
public:
    Pokemon(std::string spec);
    ~Pokemon();
    void grow(int boost);
    void harden(int boost);
    void haste(int boost);
    std::string getSpecies();
    void setSpecies(std::string spc);
    int getAttack();
    void setAttack(int atk);
    int getDefense();
    void setDefense(int def);
    int getSpeed();
    void setSpeed(int spd);
};

#endif // POKEMON_H
