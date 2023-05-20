#include <iostream>
using namespace std;

#include "Team.hpp"
using namespace ariel;

double Character::distance(Character *other)//TODO
{
    return 0.0;
}

void Character::hit(int hitP)
{
    this->hitPoints = this->hitPoints - hitP;
}

Point Character::getLocation()
{
    return this->location;
}

char *Character::print() //TODO
{
    char *string;
    return string;
}

bool Character::isAlive()
{
    if(this->hitPoints>0) return true;
    return false;
}