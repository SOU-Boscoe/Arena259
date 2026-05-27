#include <iostream>
#include <vector>
#include <memory>
#include "creature.h"
#include "creatures/clawdragon.h"
#include "creatures/jumpingspider.h"

void battle(Creature& a, Creature& b) {
	a.attack(b);
	b.specialMove(a);
}

int main() {

    std::unique_ptr<Creature> fighter =
        std::make_unique<Clawdragon>();

    Jumpingspider jumpingspider;
    fighter->specialMove(jumpingspider);

    std::vector<std::unique_ptr<Creature>> fighters;

    fighters.push_back(std::make_unique<Clawdragon>());
    fighters.push_back(std::make_unique<Jumpingspider>());

    for (auto& fighter : fighters) {
    	std::cout << fighter->getName() << std::endl;
    }

    battle(*fighters[0], *fighters[1]);

    return 0;
}

