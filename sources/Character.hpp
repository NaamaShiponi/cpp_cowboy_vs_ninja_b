#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>

#include "Point.hpp"

using namespace std;

namespace ariel
{

    class Character
    {
        Point location;
        int hitPoints;
        string name;
        bool isInTeam=false;

    public:
        Character(const string &name, const Point &location, int hitPoints) : location(location), name(name), hitPoints(hitPoints){};
        double distance(Character *other);
        void hit(int hitP);
        string getName() const { return name; }
        bool getIsInTeam() const{ return isInTeam; }
        int  getHitPoints() const{ return  hitPoints; }
        void setIsInTeam(bool isInTeam) { this->isInTeam = isInTeam;}
        Point getLocation() { return this->location; }  
        void setLocation(const Point &newlocation) { location=newlocation; }
        virtual char *print();
        bool isAlive();
        virtual~Character()
        {
        }
        Character(const Character &) = delete;
        Character &operator=(const Character &) = delete; 
        Character(Character &&) = delete;
        Character &operator=(Character &&) = delete; 
    };
};
#endif