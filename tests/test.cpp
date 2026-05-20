#include "../src/creatures/clawdragon.h"
#include <iostream>
#include "../src/creature.h"

int main(){
    Clawdragon claw;
    Creature goblin("Goblin", 100, 10);

    std::cout << claw.getName() << " health: " << claw.getHealth() << std::endl;
    std::cout << goblin.getName() << " health: " << goblin.getHealth() << std::endl;;

    claw.attack(goblin);
    claw.specialMove(goblin);

    std::cout << goblin.getName() << " health after battle: " << goblin.getHealth() << std::endl;

    // g++ -std=c++17 tests/test.cpp src/creature.cpp src/creatures/clawdragon.cpp src/rng.cpp -o test


}