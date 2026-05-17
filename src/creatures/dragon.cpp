#include "dragon.h"
#include <iostream>

Dragon::Dragon() : Creature("Dragon", 100, 15, 10, 20){}

void Dragon::specialMove(Creature& other){
    int fireDamage = 25;

    std::cout << this->getName() 
        << " uses Fire Breath on "
        << other.getName()
        << " for "
        << fireDamage
        << " damage!" << std::endl;

    other.takeDamage(fireDamage);
}