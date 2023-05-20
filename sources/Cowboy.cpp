#include <iostream>
using namespace std;

#include "Team.hpp"
using namespace ariel;

void Cowboy::shoot(Character *enemy)
{
    if (this->cartridge > 0 && this->isAlive())
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
void Cowboy::reload() {
    if(this->isAlive())
        this->cartridge = this->cartridge + 6;
}