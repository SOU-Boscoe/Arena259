#include "arena.h"
#include "creature.h"
#include <cstdlib>
#include <ctime>



int main()
{
    srand(time(0)); // begins random
    Creature c1("Alpha", 100, 15);
    Creature c2("Beta", 100, 12);

    Arena::battle(c1, c2);

    return 0;
}