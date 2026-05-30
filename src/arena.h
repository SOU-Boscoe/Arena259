#ifndef ARENA_H
#define ARENA_H

#include "creature.h"
#include<memory>
#include<vector>

// added a battle statistics function, good for debugging and generally fun

using Creatures = std::vector<std::unique_ptr<Creature>>;

class Arena
{
public:
    Arena(Creatures creatures) : creatures(std::move(creatures)) {};
    ~Arena() { std::cout << "Arena destroyed" << std::endl; }
    void battle();
	void battleRoyale();
	void tournament();
    void printBegin();
    void printTurn(int turn);
    void printWinner(Creature& winner);
	bool validateBattle(Creatures& creature);
    bool takeTurn(Creature& acting, Creature& target); // return target->isAlive()

    void addCreature(std::unique_ptr<Creature> creature);

private:
    bool hasWinner = false;
    void fightPair(Creature& a, Creature& b);
    Creatures defeated;
    Creatures creatures;
};

#endif
