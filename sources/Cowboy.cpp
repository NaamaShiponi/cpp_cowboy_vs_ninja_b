#include <iostream>
using namespace std;

#include "Team.hpp"
using namespace ariel;

void Cowboy::shoot(Character *enemy)
{
    // cout << enemy->getName()<<" " <<enemy->getHitPoints() <<endl;
    if (!this->isAlive())
        throw std::runtime_error("Cannot attack: character is not alive");

    if (!enemy->isAlive())
        throw std::runtime_error("Cannot attack: target is not alive");

    if (this == enemy)
        throw std::runtime_error("Cannot shoot oneself or invalid target");
    
        if (this->cartridge > 0)
        {
            enemy->hit(10);
            this->cartridge--;
        }
    
}
bool Cowboy::hasboolets()
{
    if (this->cartridge > 0)
        return true;
    return false;
}
void Cowboy::reload()
{
    if (!this->isAlive())
    {
        throw std::runtime_error("Cannot reload: cowboy is not alive");
    }
    if (this->isAlive())
        this->cartridge = 6;
}

