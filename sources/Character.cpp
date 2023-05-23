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

char *Character::print() 
{
    // Assuming a maximum character name length of 100 and hit points as a maximum of 1000000
    const int maxLength = 100;
    char* message = new char[maxLength];
    snprintf(message, maxLength, "Name: %s, Hit Points: %d", name.c_str(), hitPoints);

    return message;

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