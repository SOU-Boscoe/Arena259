

// C++ Libraries
#include <iostream>
#include <memory> // smart pointers
#include <vector>

#include "../src/creature.h"
#include "../src/creatures/darkjellyfish.h"
#include "../src/creatures/clawdragon.h"
#include "../src/creatures/abominablemudman.h"
#include "../src/creatures/blackhole.h"

void battle(Creature& a, Creature &b) {
	// have creatureA attack creatureB,
	// and then creatureB will preform a special move on creatureA
	a.attack(b);
	std::cout << a.getName() << " attacks " << b.getName() << "!" << std::endl;
	b.specialMove(a);
}

int main() {
	////////////
	// STEP 3 //
	////////////
	// Make a unique pointer to type of the base class, and point it to a the address of an instance of a derived class.
	// make_unique is just like "new" but for unique ptrs.
	std::unique_ptr<Creature> dragon = std::make_unique<Clawdragon>();
	
	// create an instance of another derived creature
	DarkJellyfish jellyfish;

	// Dragon attacks jellyfish, then jellyfish attacks dragon
	dragon->specialMove(jellyfish);
	jellyfish.specialMove(*dragon);

	
	////////////
	// STEP 4 //
	////////////
	// Create a vector with a bunch of fighters.
	std::vector<std::unique_ptr<Creature>> fighters;
	
	// Populate out vector with derived creatures
	fighters.push_back(std::make_unique<BlackHole>());
	fighters.push_back(std::make_unique<AbominableMudman>());

	// Loop through our creatures
	for (std::unique_ptr<Creature>& fighter : fighters) {
		std::cout << fighter->getName() << std::endl;
	}

	// Make Blackhole and Abominable Mudman fight
	battle(*fighters[0], *fighters[1]);

	return 0;
}
