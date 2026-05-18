#include <iostream>
#include "devil.h"

LordDevilious::LordDevilious()
    : Creature("Lord Devilious the 666", 120, 10)
{
}

void LordDevilious::specialMove(Creature& other)
{
    std::cout << getName()
              << " uses Hellfire Drain!"
              << std::endl;

    other.takeDamage(20);

    std::cout << getName()
              << " drains dark energy from the target!"
              << std::endl;
}