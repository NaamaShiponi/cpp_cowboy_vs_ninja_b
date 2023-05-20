#ifndef Y_NINJA_H
#define Y_NINJA_H

#include <iostream>
#include "Ninja.hpp"

namespace ariel
{

    class YoungNinja : public Ninja
    {
    public:
        YoungNinja(const std::string &name, const Point &location)
            : Ninja(name, YOUNG_NINJA_SPEED, location, YOUNG_NINJA_HITPOINTS) {}
    };
}
#endif