#ifndef T_NINJA_H
#define T_NINJA_H

#include <iostream>
#include "Ninja.hpp"

namespace ariel
{

    class TrainedNinja : public Ninja
    {
    public:
        TrainedNinja(const std::string &name, const Point &location)
            : Ninja(name, TRAINED_NINJA_SPEED, location, TRAINED_NINJA_HITPOINTS) {}
    };
}
#endif