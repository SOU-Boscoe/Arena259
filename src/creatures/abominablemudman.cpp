#ifndef ABOMINABLEMUDMAN_CPP
#define ABOMINABLEMUDMAN_CPP

#include "abominablemudman.h"

AbominableMudman::AbominableMudman()
    : Creature("Abominable Mudman", 120, 9){
}

void AbominableMudman::specialMove(Creature& other){
    int fireDamage = 25;
    std::cout << this->getName() << " uses Fire Breath on "
    << other.getName() << " for " << fireDamage << " damage!\n";

    other.takeDamage(fireDamage);
}

#endif