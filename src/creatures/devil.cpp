#include <iostream>
#include "devil.h"

LordDevilious::LordDevilious() // Constructor
    : Creature("Lord Devilious the 666", 120, 10)
{
}

void LordDevilious::specialMove(Creature& other) // Overrides the base class's specialMove function
{
    std::cout << getName() << " uses Hellfire Drain!" << std::endl;

    other.takeDamage(20);

    std::cout << getName()
              << " drains dark energy from the target!"
              << std::endl;
}