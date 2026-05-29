#ifndef ARENA_H
#define ARENA_H

#include "creature.h"
#include<memory>
#include<vector>

// added a battle statistics function, good for debugging and generally fun

class Arena
{
	private:
	std::vector<std::unique_ptr<Creature>> fighters;
	public:
		Arena();
		Arena(std::vector<std::unique_ptr<Creature>>& newfighters);
		static void battle(Creature &a, Creature &b);
		void tournament();
		static void printStats(Creature& a, Creature& b, int turns); // pass in battling creatures, total turns
		void addFighter(std::unique_ptr<Creature> fighter);
		void indexBattle(int first, int second);
};

#endif
