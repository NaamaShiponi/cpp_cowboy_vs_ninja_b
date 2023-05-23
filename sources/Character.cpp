#include <iostream>
using namespace std;

#include "Team.hpp"
using namespace ariel;

double Character::distance(Character *other)
{
    return this->location.distance(other->getLocation());
}

void Character::hit(int hitP)
{
    if (hitP < 0)
    {
        throw std::invalid_argument("Negative hit points are not allowed");
    }

    this->hitPoints = this->hitPoints - hitP;
}

char *Character::print() // TODO
{
    char *string;
    return string;
}

bool Character::isAlive()
{
    if (this->hitPoints > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}