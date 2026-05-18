#include "banshee.h"
#include <iostream>

Banshee::Banshee()
    : Creature("Banshee", 96, 17)
{
}

void Banshee::specialMove(Creature& other)
{
    std::cout << "Banshee unleashes a piercing wail!" << std::endl;
    other.takeDamage(22);
    incDamageDealt(22);
}
