#ifndef ARENA_H
#define ARENA_H

#include "creature.h"
#include <vector>
#include <memory>

// added a battle statistics function, good for debugging and generally fun

class Arena
{
	private:
		std::vector<std::unique_ptr<Creature>> fighters;
	public:
		void battle(int first, int second);
		static void printStats(Creature& a, Creature& b, int turns); // pass in battling creatures, total turns
		void addFighter(std::unique_ptr<Creature> fighter);
};

#endif
