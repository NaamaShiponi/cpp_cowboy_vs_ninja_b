#include <iostream>
using namespace std;

#include "Team.hpp"
using namespace ariel;


    double Point::distance(const Point &other){return 3.3;}
    bool Point::operator==(const Point& other) const {
        if(this->getX()==other.getX() &&this->getY()==other.getY()) return true;
        return false;
    }

    void Point::print(){}
    Point Point::moveTowards(Point &source, Point &destination, double distance){ return source;}
