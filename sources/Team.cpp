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
    if (listCharacter.size() == 10)
        throw std::runtime_error("Team is already at maximum capacity");
    if (member->getIsInTeam())
        throw std::runtime_error("Teammate is already assigned to another team");

    if (dynamic_cast<Cowboy *>(member) != nullptr)
    {
        // Add Cowboy character at the beginning of the list
        listCharacter.insert(listCharacter.begin(), member);
    }
    else
    {
        // Find the index to insert the Ninja after the last Cowboy (if any)
        auto it = std::find_if(listCharacter.rbegin(), listCharacter.rend(), [](Character *c) {
            return dynamic_cast<Cowboy *>(c) != nullptr;
        });
        if (it == listCharacter.rend())
        {
            // No Cowboys found, add Ninja character at the beginning of the list
            listCharacter.insert(listCharacter.begin(), member);
        }
        else
        {
            // Insert Ninja after the last Cowboy
            listCharacter.insert(it.base(), member);
        }
    }

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
void Team::print()
{
    cout << "Team Leader: " << leader->getName() << endl;
    cout << "Team Members: " << endl;
    for (Character *member : listCharacter)
    {
        cout << "- " << member->getName() << " HitPoints " << member->getHitPoints() << endl;
    }
}



void SmartTeam::add(Character *member)
{
    if (this->listCharacter.size() == 10)
        throw std::runtime_error("Team is already at maximum capacity");
    if (member->getIsInTeam())
        throw std::runtime_error("Teammate is already assigned to another team");

    this->listCharacter.emplace_back(member);
    member->setIsInTeam(true);
}