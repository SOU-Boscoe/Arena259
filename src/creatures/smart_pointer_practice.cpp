#include <iostream>
#include <memory>
#include <vector>

#include "../creature.h"
#include "clawdragon.h"
#include "devil.h"
// step 6 
void battle(Creature& a, Creature& b) {
    a.attack(b);
    b.specialMove(a);
}

int main() {
    // Create a vector that stores smart pointers to creatures:
    std::vector<std::unique_ptr<Creature>> fighters;

    // Add at least two different creature types:
    fighters.push_back(std::make_unique<Clawdragon>());
    fighters.push_back(std::make_unique<LordDevilious>());

    // Step 5: loop through the fighters:
    for (auto& fighter : fighters) {
        std::cout << fighter->getName() << std::endl;
    }

    battle(*fighters[0], *fighters[1]);

    return 0;
}
