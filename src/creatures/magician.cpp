#include <iostream>
#include "magician.h"

Magician::Magician() : Creature("Magician", 120, 20, 10, 20){}

void Magician::specialMove(Creature& other){
    int magicHealing = this->getHealing();
    
    this->health += magicHealing;
    if (this->health > this->maxHealth){
        this->health = this->maxHealth;
    }

    std::cout << this->getName()
        << " heals self for "
        << magicHealing
        << " health!"
        << std::endl; 
}