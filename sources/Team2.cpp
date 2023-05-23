#include <iostream>
using namespace std;

#include "Team2.hpp"
using namespace ariel;

void Team2::add(Character *member)
{
    if (this->listCharacter.size() == 10)
        throw std::runtime_error("Team is already at maximum capacity");
    if (member->getIsInTeam())
        throw std::runtime_error("Teammate is already assigned to another team");

    this->listCharacter.emplace_back(member);
    member->setIsInTeam(true);
}