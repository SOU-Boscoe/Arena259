#include <iostream>
#include <memory>
#include "../creature.h"
#include "clawdragon.h"
#include "darkjellyfish.h"
#include <vector>

void battle(Creature& a, Creature& b){
    a.attack(b);
    b.specialMove(a);
}

int main(){

    std::unique_ptr<Creature> fighter = std::make_unique<Clawdragon>();

    DarkJellyfish goblin;
    fighter->specialMove(goblin);

    std::vector<std::unique_ptr<Creature>> fighters;

    fighters.push_back(std::make_unique<Clawdragon>());
    fighters.push_back(std::make_unique<DarkJellyfish>());
    
    for(auto& fighter : fighters){
        std::cout << fighter->getName() << std::endl;
    }

    battle(*fighters[0], *fighters[1]);


    return 0;
}

// g++ -std=c++17 src/creature.cpp src/rng.cpp src/creatures/clawdragon.cpp src/creatures/darkjellyfish.cpp src/creatures/smart_pointer_practice.cpp -o smart_pointer_practice


