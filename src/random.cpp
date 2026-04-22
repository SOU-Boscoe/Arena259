#include "random.h"

bool Random::flipCoin() { return COIN(yield); }

int Random::randomValue(int min, int max) { return std::uniform_int_distribution<>{min, max}(yield); }