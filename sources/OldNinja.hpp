#ifndef O_NINJA_H
#define O_NINJA_H

#include <iostream>
#include "Ninja.hpp"
namespace ariel
{

    class OldNinja : public Ninja
    {
    public:
        OldNinja(const std::string &name, const Point &location)
            : Ninja(name, OLD_NINJA_SPEED, location, OLD_NINJA_HITPOINTS) {}
    };
}
#endif