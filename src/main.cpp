#include "arena.h"
#include "creature.h"
#include "./creatures/sumo_sally.h"
#include "./creatures/giantleech.h"
#include "./creatures/clawdragon.h"
#include <memory>

int main()
{
    // Creature c1(make_sumo_sally());
    // Creature c2(makeGiantleech());
    
    // std::cout << "Total creatures created: " << Creature::getCreatureCount() << std::endl; // print out the number of creatures in the arena

    // Arena::battle(c1, c2);

    Arena arena;

    arena.addFighter(std::make_unique<Clawdragon>());
    arena.addFighter(std::make_unique<Clawdragon>());

    arena.battle(0, 1);

    auto dragon = std::make_unique<Clawdragon>();
    arena.addFighter(std::move(dragon));


    return 0;
}

// g++ -std=c++17 ./src/main.cpp ./src/creature.cpp ./src/arena.cpp ./src/rng.cpp ./src/creatures/clawdragon.cpp -o ./arena