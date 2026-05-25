#include <iostream>
#include <memory>
#include "creature.h"
#include "./creatures/magician.h"
#include "./creatures/grumpywizard.h"
#include "./creatures/clawdragon.h"
#include "./creatures/jumpingspider.h"

void battle(Creature& a, Creature& b) {
    a.attack(b);
    b.specialMove(a);

    std::cout << a.getName() << " has " << a.getHealth() << " HP left" << std::endl;
    std::cout << b.getName() << " has " << b.getHealth() << " HP left" << std::endl;
    }

int main() {

    std::vector<std::unique_ptr<Creature>> fighters;

    fighters.push_back(std::make_unique<Clawdragon>());
    fighters.push_back(std::make_unique<Jumpingspider>());

    for (auto& fighter : fighters) {
    std::cout << fighter->getName() << std::endl;
    }

    battle(*fighters[0], *fighters[1]);

    std::unique_ptr<Creature> magician =
        std::make_unique<Magician>();

    std::unique_ptr<Creature> wizard =
        std::make_unique<GrumpyWizard>();
    

    magician->specialMove(*wizard);
    return 0;
}
