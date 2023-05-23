#include <iostream>
using namespace std;


#include "Team.hpp"
using namespace ariel;

// void Ninja::move(Character* enemy) {
//     if (!this->isAlive())
//         throw std::runtime_error("Cannot move: character is not alive");

//     if (!enemy->isAlive())
//         throw std::runtime_error("Cannot move: target is not alive");

//     if (this->getLocation() == enemy->getLocation())
//         throw std::runtime_error("Cannot move: already at the target location");

//     Point::moveTowards(this->getLocation(),enemy->getLocation(),speed);
    // // Calculate the initial distance to the enemy
    // double distance = this->getLocation().distance(enemy->getLocation());

    // // Calculate the direction towards the enemy
    // double deltaX = (enemy->getLocation().getX() - this->getLocation().getX()) / distance;
    // double deltaY = (enemy->getLocation().getY() - this->getLocation().getY()) / distance;

    // // Move towards the enemy step by step
    // while (distance >= this->getSpeed()) {
    //     // Calculate the number of steps needed to reach the enemy based on the updated distance
    //     int steps = static_cast<int>(distance / this->getSpeed());

    //     // Update the ninja's location step by step
    //     for (int i = 0; i < steps; i++) {
    //         double newX = this->getLocation().getX() + (deltaX * this->getSpeed());
    //         double newY = this->getLocation().getY() + (deltaY * this->getSpeed());

    //         // Update the ninja's location
    //         this->setLocation(Point(newX, newY));
    //     }

    //     // Recalculate the distance to the enemy
    //     distance = this->getLocation().distance(enemy->getLocation());
    // }

    // // Move the remaining distance in one step
    // this->setLocation(enemy->getLocation());
// }
void Ninja::move(Character* enemy) {
    if (!this->isAlive())
        throw std::runtime_error("Cannot move: character is not alive");

    if (!enemy->isAlive())
        throw std::runtime_error("Cannot move: target is not alive");

    if (this->getLocation() == enemy->getLocation())
        throw std::runtime_error("Cannot move: already at the target location");

    Point source = this->getLocation();
    Point destination = enemy->getLocation();
    Point newLocation = Point::moveTowards(source, destination, speed);

    this->setLocation(newLocation);
}


void Ninja::slash(Character *enemy)
{
    if (!this->isAlive()) 
        throw std::runtime_error("Cannot attack: character is not alive");
    

    if (!enemy->isAlive()) 
        throw std::runtime_error("Cannot attack: target is not alive");
    
    if(this == enemy)
        throw std::runtime_error("Cannot slash oneself or invalid target");

    if(this->isAlive() && this->distance(enemy)<1 && enemy->isAlive()) 
        enemy->hit(40);
}
