#ifndef ARENA_H
#define ARENA_H

#include "creature.h"
#include <vector>
#include <cstdlib>
#include <ctime>
#include <memory>


// added a battle statistics function, good for debugging and generally fun

class Arena
{
private:
    std::vector<std::unique_ptr<Creature>> fighters;

public:
    void addFighter(std::unique_ptr<Creature> fighter);
    void battle(int first, int second);

    static void battle(Creature &a, Creature &b);
};
#endif