#include "Pokemon.h"

Pokemon::Pokemon(std::string spec)
{
    species = spec;
    attack = (species.length()*4)+2;
    defense = (species.length()*2)+7;
    speed = (species.length()*3)+5;
}

Pokemon::~Pokemon()
{
}

void Pokemon::grow(int boost)
{
    attack += boost;
}
void Pokemon::harden(int boost)
{
    defense += boost;
}
void Pokemon::haste(int boost)
{
    speed += boost;
}
std::string Pokemon::getSpecies()
{
    return species;
}
void Pokemon::setSpecies(std::string spc)
{
    species = spc;
}
int Pokemon::getAttack()
{
    return attack;
}
void Pokemon::setAttack(int atk)
{
    attack = atk;
}
int Pokemon::getDefense()
{
    return defense;
}
void Pokemon::setDefense(int def)
{
    defense = def;
}
int Pokemon::getSpeed()
{
    return speed;
}
void Pokemon::setSpeed(int spd)
{
    speed = spd;
}

