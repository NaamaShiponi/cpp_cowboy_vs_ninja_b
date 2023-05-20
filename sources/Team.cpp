#include <iostream>
using namespace std;

#include "Team.hpp" 
using namespace ariel;

Team::Team(Character *leader): leader(leader){}
void Team::add(Character *leader){}
void Team::attack(const Team* enemy){}
int Team::stillAlive(){return 0;}
void Team::print(){}




void SmartTeam::attack(const Team *enemy){}
int SmartTeam::stillAlive(){return 0;}
void SmartTeam::print(){}