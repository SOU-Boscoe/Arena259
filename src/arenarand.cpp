#include "arenarand.h"


bool ArenaRand::flipCoin() { return COIN(gen); }

int ArenaRand::randomValue(int min, int max) { return std::uniform_int_distribution<>{min, max}(gen); }