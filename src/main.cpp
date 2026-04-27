#include "arena.h"
#include "creature.h"
#include "./creatures/sumo_sally.h"
#include "./creatures/giantleech.h"

int main()
{
    // Updated: Pass type to constructor (enhancement). Assumed types based on creature names; adjust as needed.
    Creature c1(make_sumo_sally());  // Assuming make_sumo_sally returns Creature("sumo_sally", 120, 10, "Humanoid") or similar.
    Creature c2(makeGiantleech());   // Assuming makeGiantleech returns Creature("Giant Leech", 100, 15, "Beast") or similar.

    // Required: Print total creatures created.
    std::cout << "Total creatures created: " << Creature::getCreatureCount() << std::endl;

    Arena::battle(c1, c2);

    return 0;
}