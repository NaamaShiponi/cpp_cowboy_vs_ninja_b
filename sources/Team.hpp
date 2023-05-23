#ifndef TEAM_H
#define TEAM_H

#include <iostream>
#include <vector>
#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "Point.hpp"

using namespace std;

namespace ariel
{

    class Team
    {
        vector<Character *> listCharacter;
        Character *leader;

    public:
        Team(Character *leader);
        ~Team()
        {
            for (Character *member : listCharacter)
            {
                delete member;
            }
        }
        Team(const Team &) = delete;
        Team &operator=(const Team &) = delete; 
        Team(Team &&) = delete;
        Team &operator=(Team &&) = delete; 

        void add(Character *member);
        void attack(const Team *enemy);
        int stillAlive() const;
        void print();
    };

    class SmartTeam : public Team
    {
    public:
        SmartTeam(Character *leader) : Team(leader) {}
        void attack(const Team *enemy);
        void print();
    };

}

#endif
