#include "arena.h"
#include "creature.h"
#include "./creatures/devil.h"
#include "./creatures/darkjellyfish.h"

// C++ libraries
#include <memory>

int main()
{
	Arena a;
	a.addFighter(std::make_unique<LordDevilious>());
	a.addFighter(std::make_unique<DarkJellyfish>());

	a.battle(0, 1);

	return 0;
}
