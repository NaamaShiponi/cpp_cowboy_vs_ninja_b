#ifndef COWBOY_H
#define COWBOY_H
#include <iostream>
#include "Point.hpp"
#include "Character.hpp"

using namespace std;

namespace ariel
{

    class Cowboy : public Character
    {
        int cartridge;

    public:
        static const int CARTR = 6;
        static const int HITPOINTS = 110;
        Cowboy(const string &name, const Point &location) : cartridge(CARTR),Character(name, location, HITPOINTS){};
        ~Cowboy(){}; //TODO
        Cowboy(const Cowboy&) = delete;            // Delete copy constructor
        Cowboy& operator=(const Cowboy&) = delete; // Delete copy assignment operator
        Cowboy(Cowboy&&) = delete;                 // Delete move constructor
        Cowboy& operator=(Cowboy&&) = delete;      // Delete move assignment operator


        void shoot(Character *enemy);
        bool hasboolets();
        void reload();
    };
};
#endif