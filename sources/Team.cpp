#include <iostream>
using namespace std;
#include <limits>
#include "Team.hpp"
using namespace ariel;

Team::Team(Character *newleader)
{
    if (newleader->getIsInTeam())
    {
        throw std::runtime_error("Captain is already assigned to another team");
    }

    newleader->setIsInTeam(true);
    leader = newleader;
    listCharacter.emplace_back(newleader);
}

void Team::add(Character *member)
{
    if (this->listCharacter.size() == 10)
        throw std::runtime_error("Team is already at maximum capacity");
    if (member->getIsInTeam())
        throw std::runtime_error("Teammate is already assigned to another team");

    this->listCharacter.emplace_back(member);
    member->setIsInTeam(true);
}

void Team::attack(const Team *enemy)
{
    if (enemy == nullptr)
    {
        throw std::invalid_argument("Invalid enemy team");
    }
    if (enemy->stillAlive() == 0)
    {
        throw std::runtime_error("Attacking a dead team");
    }
    if (leader == nullptr || !leader->isAlive()) // check leader
    {
        double minDistance = std::numeric_limits<double>::max();
        Character *closestCharacter = nullptr;

        for (Character *character : listCharacter)
        {
            if (character->isAlive())
            {
                double distance = leader->distance(character);
                if (distance < minDistance)
                {
                    minDistance = distance;
                    closestCharacter = character;
                }
            }
        }

        if (closestCharacter != nullptr)
        {
            leader = closestCharacter;
        }
        else
        {
            // No available leader, attack cannot proceed
            return;
        }
    }

    if (enemy->stillAlive() > 0 && stillAlive() > 0)
    {
        double minDistance = std::numeric_limits<double>::max();
        Character *closestCharacter = nullptr;

        for (Character *enemyCharacter : enemy->listCharacter)
        {
            if (enemyCharacter->isAlive())
            {
                double distance = leader->distance(enemyCharacter);
                if (distance < minDistance)
                {
                    minDistance = distance;
                    closestCharacter = enemyCharacter;
                }
            }
        }

        if (closestCharacter != nullptr)
        {
            for (Character *character : listCharacter)
            {
                
                if (character->isAlive())
                {
                    if (Cowboy *cowboy = dynamic_cast<Cowboy *>(character))
                    {
                        if (cowboy->hasboolets())
                        {
                            cowboy->shoot(closestCharacter);
                        }
                        else
                        {
                            cowboy->reload();
                        }
                    }
                    else if (Ninja *ninja = dynamic_cast<Ninja *>(character))
                    {
                        if (ninja->distance(closestCharacter) <= 1)
                        {
                            ninja->slash(closestCharacter);
                        }
                        else
                        {
                            // Move ninja closer to the victim
                            ninja->move(closestCharacter);
                        }
                    }
                }
                if (!closestCharacter->isAlive())
                {
                    closestCharacter = nullptr;
                    if (enemy->stillAlive()>0)
                    {
                        minDistance = std::numeric_limits<double>::max();
                        for (Character *enemyCharacter : enemy->listCharacter)
                        {
                            if (enemyCharacter->isAlive())
                            {
                                double distance = leader->distance(enemyCharacter);
                                if (distance < minDistance)
                                {
                                    minDistance = distance;
                                    closestCharacter = enemyCharacter;
                                }
                            }
                        }
                    }
                    if (closestCharacter == nullptr)
                    {
                        return;
                    }
                }
                
            }
        }
    }
}



int Team::stillAlive() const
{
    int count = 0;
    for (size_t i = 0; i < listCharacter.size(); i++)
    {
        if (listCharacter[i]->isAlive())
            count++;
    }
    return count;
}
void Team::print() {} // TODO

void SmartTeam::attack(const Team *enemy) {} // TODO
void SmartTeam::print() {}                   // TODO