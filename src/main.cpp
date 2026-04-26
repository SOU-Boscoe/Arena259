#include "arena.h"
#include "creature.h"
#include "./creatures/viper.h"
#include "./creatures/giantleech.h"

int main()
{
    Creature c1(makeViper());
    Creature c2(makeGiantleech());

    std::cout << "The total creatures created: " << Creature::getCreatureCount() << std::endl;
    Arena::battle(c1, c2);

    return 0;
}