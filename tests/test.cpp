#include <iostream>
#include "creature.h"
#include "dragon.h"

int main() {

    Dragon dragon;

    Creature goblin("Goblin", 50, 8);

    std::cout << dragon.getName()
              << " health: "
              << dragon.getHealth()
              << std::endl;

    std::cout << goblin.getName()
              << " health: "
              << goblin.getHealth()
              << std::endl;

    dragon.attack(goblin);

    dragon.specialMove(goblin);

    std::cout << goblin.getName()
              << " health after battle: "
              << goblin.getHealth()
              << std::endl;

    return 0;
}



// Which object is a Dragon? the dragon variable is a Dragon object
// Which object is a plain Creature? the goblin variable is a plain Creature object
// What happens when this line runs? dragon.attack(goblin); // the dragon attacks the goblin, which decreases the goblin's health by the dragon's damage (15), so the goblin's health goes from 50 to 35
// What happens when this line runs? dragon.specialMove(goblin); // the dragon uses its special move, Fire Breath, dealing 25 damage to the goblin
// Which function came from the base class? getName(), getHealth(), getDamage(), attack(), takeDamage()
// Which function came from the derived class? specialMove()