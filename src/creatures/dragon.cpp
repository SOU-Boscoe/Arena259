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

// What is the constructor for the Dragon class? Dragon::Dragon() : Creature("Dragon", 100, 15) {}
// What base class constructor is being called? Creature("Dragon", 100, 15)
// What are the constructor arguments? "Dragon", 100, 15
// What does each argument represent? "Dragon" is the name of the creature, 100 is the health, and 15 is the damage
// Why can Dragon use name directly? Because name is a protected member of the Creature class, and Dragon is a derived class of Creature, so it can access protected members of Creature directly
// Why does other.getName() use a getter instead of other.name? Because name is a protected member of Creature, and other is a reference to a Creature object, so we cannot access name directly from other, we have to use the getter getName() to access it
// What makes specialMove() different from a normal attack? It is a special move that has a different name and does a different amount of damage than the normal attack, and it can be overridden by derived classes to have different effects in battle

