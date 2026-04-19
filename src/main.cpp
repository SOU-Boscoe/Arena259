#include "arena.h"
#include "creature.h"
#include "./creatures/viper.h"
#include "./creatures/giantleech.h"
#include "./creatures/clawdragon.h"
#include "./creatures/segoblin.h"
#include "./creatures/sumo_sally.h"
#include "./creatures/boogeyman.h"

int main()
{
    Creature c1(makeViper());
    Creature c2(makeGiantleech());
    Creature c3(make_sumo_sally());
    Creature c4(makeBoogeyman());
    Creature c5(makeClawdragon());
    Creature c6(makeSEGoblin());
    Creature c7(makeGiantleech());
    Creature c8(Creature("Bro", 42, 21));

    Arena::tournament(c1, c2 ,c3 ,c4 ,c5, c6, c7, c8);

    return 0;
}