#include <iostream>
#include <memory>
#include "creature.h"
#include "creatures/grumpywizard.h"

int main() {

    auto gw     = std::make_unique<GrumpyWizard>();
    auto goblin = std::make_unique<Creature>("Goblin", 50, 8);

    std::cout << gw->getName()
              << " health: "
              << gw->getHealth()
              << std::endl;

    std::cout << goblin->getName()
              << " health: "
              << goblin->getHealth()
              << std::endl;

    gw->attack(*goblin);

    gw->specialMove(*goblin);

    std::cout << goblin->getName()
              << " health after battle: "
              << goblin->getHealth()
              << std::endl;

    return 0;
}
