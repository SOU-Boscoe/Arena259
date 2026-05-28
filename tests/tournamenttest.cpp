#include "../src/arena.h"
#include "../src/creature.h"
#include "../src/creatures.h"

int main() {

    std::vector<std::unique_ptr<Creature>> fighters;

    fighters.push_back(std::make_unique<AbominableMudman>());
    fighters.push_back(std::make_unique<Banshee>());
    fighters.push_back(std::make_unique<BlackHole>());
    fighters.push_back(std::make_unique<Clawdragon>());
    fighters.push_back(std::make_unique<DarkJellyfish>());
    fighters.push_back(std::make_unique<LordDevilious>());
    fighters.push_back(std::make_unique<GrumpyWizard>());
    fighters.push_back(std::make_unique<Jumpingspider>());
    fighters.push_back(std::make_unique<Magician>());
    fighters.push_back(std::make_unique<RingmasterHawk>());
    fighters.push_back(std::make_unique<Jeff>());


    // Factory-returned Creature objects
    fighters.push_back(std::make_unique<Creature>(make_sumo_sally()));
    fighters.push_back(std::make_unique<Creature>(makeBoogeyman()));
    fighters.push_back(std::make_unique<Creature>(makeGiantleech()));
    fighters.push_back(std::make_unique<Creature>(makeSEGoblin()));

    Arena::tournament(fighters);

    return 0;
}