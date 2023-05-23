#ifndef TEAM2_H
#define TEAM2_H

#include "Character.hpp"
#include "Team.hpp"


namespace ariel {


 class Team2 : public Team {
    public:
        Team2(Character* leader) : Team(leader) {}
        void attack(const Team* enemy);
        void print();
    };

}

#endif