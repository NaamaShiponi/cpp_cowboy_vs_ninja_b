#ifndef NINJA_H
#define NINJA_H

#include <iostream>
#include "Point.hpp"
#include "Character.hpp"

namespace ariel
{

    class Ninja : public Character
    {
        int speed;

    public:
        static const int OLD_NINJA_SPEED = 8;
        static const int OLD_NINJA_HITPOINTS = 150;
        static const int YOUNG_NINJA_SPEED = 14;
        static const int YOUNG_NINJA_HITPOINTS = 100;
        static const int TRAINED_NINJA_SPEED = 12;
        static const int TRAINED_NINJA_HITPOINTS = 120;

        Ninja(const std::string &name, int speed, const Point &location, int hitPoints)
            : Character(name, location, hitPoints), speed(speed){}
        Ninja(const Ninja &) = delete; //TODO
        Ninja &operator=(const Ninja &) = delete; //TODO
        Ninja(Ninja &&) = delete; //TODO
        Ninja &operator=(Ninja &&) = delete; //TODO
        ~Ninja(){}; //TODO
        int getSpeed() const { return speed; }
        void move(Character *enemy);
        void slash(Character *enemy);
    };

}

#endif
