#ifndef ARENA_H
#define ARENA_H

#include "creature.h"
#include <vector>
#include <cstdlib>
#include <ctime>

// added a battle statistics function, good for debugging and generally fun

// added a battle statistics function, good for debugging and generally fun

class Arena
{
<<<<<<< HEAD
	private:
	
	public:
		static void battle(Creature &a, Creature &b);
		static void printStats(Creature& a, Creature& b, int turns); // pass in battling creatures, total turns
=======
public:
    static void battle(Creature &a, Creature &b);

//    static void Colluseum(std::vector<Creature> creatures);
>>>>>>> 21cb0b3 (fixing issues because of sync)
};

#endif
