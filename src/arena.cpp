#include <iostream>
#include <iomanip>
#include "arena.h"
#include "rng.h"

void Arena::battle(int first, int second)
{
	// First here is the index of the fighter to use in our vector of fighters
    	// likewise for second
	
	// First, check that the creature's HP and Damage stats are within a valid range.
	if (!Creature::validateBattle(*fighters[first], *fighters[second])) {
	 	return; // if not, then just end the battle early.
	}

	// Print our fighters names
    	std::cout << fighters[first]->getName() << " vs " << fighters[second]->getName() << std::endl;
	std::cout << "Battle start!" << std::endl;

	// Have fighter1 attack fighter2,
	// Then fighter2 use a special move on fighter1
	fighters[first]->attack(*fighters[second]);
	if (fighters[second]->isAlive()) { // Check if fighter2 is alive before using a special move
		fighters[second]->specialMove(*fighters[first]);
	}
	else {
		std::cout << fighters[second]->getName() << " has been defeated!" << std::endl;
	}
	if (!fighters[first]->isAlive()) { // Check if fighter1 has died
		std::cout << fighters[first]->getName() << " has been defeated!" << std::endl;
	}

	// Print out battle results
	std::cout << "End battle!" << std::endl;
	std::cout << fighters[first]->getName() << " HP: " << fighters[first]->getHealth() << std::endl;
	std::cout << fighters[second]->getName() << " HP: " << fighters[second]->getHealth() << std::endl;
}

void Arena::printStats(Creature& a, Creature& b, int turns) {

    // print winner
    std::cout << "Battle finished, the winner is ";
    if (a.isAlive())
    {
        std::cout << a.getName() << "!" << std::endl;
    }
    else
    {
        std::cout << b.getName() << "!" << std::endl;
    }

    // arena stats
    std::cout << "Total turns: " << turns << std::endl;
    std::cout << "Total Damage Dealt: " << a.getDamageDealt() + b.getDamageDealt() << std::endl;
    std::cout << std::endl;

    // a creature stats
    std::cout << a.getName() << " Health: " << a.getHealth() << "/" << a.getStartHealth() << std::endl;
    std::cout << a.getName() << " Damage Dealt: " << a.getDamageDealt() << std::endl;
    std::cout << std::endl;

    // b creature stats
    std::cout << b.getName() << " Health: " << b.getHealth() << "/" << b.getStartHealth() << std::endl;
    std::cout << b.getName() << " Damage Dealt: " << b.getDamageDealt() << std::endl;

}

void Arena::addFighter(std::unique_ptr<Creature> fighter) {
	fighters.push_back(std::move(fighter)); // add the fighter to our vectors of fighters
	std::cout << "Arena now has" << fighters.size() << "fighters" << std::endl;
}
