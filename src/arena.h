#ifndef ARENA_H
#define ARENA_H

#include <vector>
#include <memory>

#include "creature.h"

// added a battle statistics function, good for debugging and generally fun

class Arena
{
	private:
		std::vector<std::unique_ptr<Creature>> fighters;

	public:
		static void battle(Creature &a, Creature &b);
		static void printStats(Creature& a, Creature& b, int turns); // pass in battling creatures, total turns
		void addFighter(std::unique_ptr<Creature> fighter);
		void battle(int first, int second);
};

#endif
