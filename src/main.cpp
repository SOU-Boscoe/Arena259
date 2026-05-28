#include "arena.h"
#include "creature.h"
#include "./creatures/sumo_sally.h"
#include "./creatures/giantleech.h"

#include <memory>

using namespace std;

int main()
{
Arena arena;

auto fighter1 =
    make_unique<Creature>(make_sumo_sally());

auto fighter2 =
    make_unique<Creature>(makeGiantleech());

arena.addFighter(std::move(fighter1));
arena.addFighter(std::move(fighter2));

arena.battle(0, 1);

return 0;
}