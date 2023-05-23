#include <iostream>
#include <cmath>

using namespace std;

#include "Team.hpp"
using namespace ariel;

double Point::distance(const Point &other)
{

    double dx = other.getX() - x_axis;
    double dy = other.getY() - y_axis;
    return std::sqrt(dx * dx + dy * dy);
}

bool Point::operator==(const Point &other) const
{
    if (this->getX() == other.getX() && this->getY() == other.getY())
        return true;
    return false;
}

void Point::print()
{
    cout << "( " << this->getX() << " , " << this->getY() << " )";
}

Point Point::moveTowards(Point &source, Point &destination, double distance)
{
    if (distance < 0)
    {
        throw std::invalid_argument("Negative distance is not allowed");
    }
    double dx = destination.getX() - source.getX();
    double dy = destination.getY() - source.getY();
    double currentDistance = source.distance(destination);

    // Calculate the ratio to move towards the destination
    double ratio = distance / currentDistance;

    // Calculate the new point coordinates
    double newX = source.getX() + dx * ratio;
    double newY = source.getY() + dy * ratio;


    double d = source.distance(destination);

    if (d <= distance)
        return destination;
    
    return Point(newX, newY);
}
