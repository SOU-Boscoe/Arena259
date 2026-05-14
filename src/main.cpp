#include "arena.h"
#include "creature.h"
#include "./creatures/magician.h"
#include "./creatures/dragon.h"

int main()
{
    Creature c1{Magician()};
    Creature c2{Dragon()};

    // Only addition to main. Prints total number of creatures using new methods implemented in creature.h
    std::cout << "Total creatures created: "
              << Creature::getCreatureCount() << std::endl;

    Arena::battle(c1, c2);

    return 0;
}
