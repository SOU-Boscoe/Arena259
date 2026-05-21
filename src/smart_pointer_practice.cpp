#include <iostream>
#include <memory>
#include <vector>
#include "creature.h"
#include "creatures/blackhole.h"
#include "creatures/grumpywizard.h"

// small scale battle function for test
void battle(Creature&a, Creature& b) {
    a.attack(b);
    b.specialMove(a);
}

int main() {
    // STEP 3: creating a unique pointer object of type Creature (or derived classes due to polymorphism) that currently stores a BlackHole Creature
    std::unique_ptr<Creature> solo_fighter = std::make_unique<BlackHole>();

    // use the unique ptr object fighter with arrow operator to execute special move on gw
    GrumpyWizard gw;
    solo_fighter->specialMove(gw);

    // STEP 4: create a vector of pointers to creatures called fighters, and add creature types to vector
    std::vector<std::unique_ptr<Creature>> fighters;

    // must use make_unique here, otherwise the vector would try to store by value which mismatches vector type
    fighters.push_back(std::make_unique<GrumpyWizard>());
    fighters.push_back(std::make_unique<BlackHole>());

    // STEP 5: loop through the fighters vector and output names for each
    for (auto& fighter : fighters) {
        std::cout << fighter->getName() << std::endl;
    }

    // STEP 6: mini battle function
    battle(*fighters[0], *fighters[1]);

    return 0;
}

