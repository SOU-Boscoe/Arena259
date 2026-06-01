#ifndef ARENA_H
#define ARENA_H

#include "creature.h"
#include "rng.h"
#include <memory>
#include <vector>

// added a battle statistics function, good for debugging and generally fun

using Creatures = std::vector<std::unique_ptr<Creature>>;

enum class RoundEvent {
    NONE = 0,
    STRENGTH_EVENT,
    SPECIAL_EVENT,
};

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

    RoundEvent rollRoundEvent();
    void announceRoundEvent(RoundEvent event);
    void applyRoundEvent(RoundEvent event);

    void addCreature(std::unique_ptr<Creature> creature);

private:
    bool hasWinner = false;
    int eventAttackBonus = 0;
    bool specialMovesDisabled = false;
    void fightPair(Creature& a, Creature& b);
    Creatures defeated;
    Creatures creatures;
};

#endif
