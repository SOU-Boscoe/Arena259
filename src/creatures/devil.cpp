#include <iostream>
#include "devil.h"


LordDevilious::LordDevilious() // constructor that initializes the base class with specific values for name, health, and damage
    : Creature("Lord Devilious the 666", 120, 10)
{
}

void LordDevilious::specialMove(Creature& other) // override the base class special move with a unique one for this creature
{
    std::cout << getName() // print out the name of the creature using the special move
              << " uses Hellfire Drain!"
              << std::endl;

    other.takeDamage(20);

    std::cout << getName() // drain health from the target
              << " drains dark energy from the target!"
              << std::endl;
}