#include "dragon.h"
#include <iostream>

Dragon::Dragon()
: Creature("Dragon", 100, 15) {

}

void Dragon::specialMove(Creature& other) {
    int fireDamage = 25;

    std::cout << this->getName()
    << " uses Fire Breath on "
    << other.getName()
    << " for "
    << fireDamage
    << " damage!" << std::endl;
    
    other.takeDamage(fireDamage);
}

// what constructor is being called? the default constructor of the base class Creature
// what are the constructor arguments? the name "Dragon", health 100, and attack power 15 are being passed to the Creature constructor
// what does each argument represent? the name represents the name of the creature, health represents the initial health points of the creature, and attack power represents the damage the creature can inflict in a normal attack
// why can Dragon use name directly? because Dragon inherits from Creature, it can access the protected member variable name defined in the Creature class
