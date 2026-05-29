#include "arena.h"
#include "creature.h"
#include "creatures.h"

int main()
{
    Arena arena = Arena();

    arena.addFighter(std::make_unique<AbominableMudman>());
    auto spider = std::make_unique<Jumpingspider>();
    arena.addFighter(std::move(spider));


    arena.indexBattle(0,1);

    // Because of inheritance hieherarchy, Mudman destructor is called first, then because Mudman is also a Creature,
    // Creature destructor is called on mudman, then because spider has to output for its destructor it is still called,
    // and then the Creature destructor is called and output on spider.

    return 0;
}
