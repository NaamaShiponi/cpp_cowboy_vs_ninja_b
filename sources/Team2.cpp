#include <iostream>
using namespace std;

#include "Team2.hpp"
using namespace ariel;

void Team2::attack(const Team *enemy)
{
    if (enemy == nullptr)
    {
        throw std::invalid_argument("Invalid enemy team");
    }
}
void Team2::print() {} // TODO
