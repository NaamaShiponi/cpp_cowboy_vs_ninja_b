#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>

#include "Point.hpp"



using namespace std;

namespace ariel{

    class Character{
        Point location;
        int hitPoints;
        string name;

        public:
            Character(const string &name,const Point &location,int hitPoints):location(location),name(name),hitPoints(hitPoints){};
            double distance(Character *other);
            void hit(int hitP);
            string getName() const {return name;}
            Point getLocation();
            char* print();
            bool isAlive();
            
    };
};
#endif