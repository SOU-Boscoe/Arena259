#include <iostream>
#include "arena.h"

void Arena::battle(Creature &first, Creature &second)
{
        
    std::cout << first.getName() << " vs " << second.getName() << std::endl;

    int turn = 1;

    while (first.isAlive() && second.isAlive())
    {
        std::cout << "\nTurn " << turn << std::endl;

        std::cout << first.getName() << " attacks!" << std::endl;
        first.attack(second);
        std::cout << second.getName() << " health: " << second.getHealth() << std::endl;

        if (!second.isAlive())
        {
            std::cout << first.getName() << " wins!" << std::endl;
            return;
        }

        std::cout << second.getName() << " attacks!" << std::endl;
        second.attack(first);
        std::cout << first.getName() << " health: " << first.getHealth() << std::endl;

        if (!first.isAlive())
        {
            std::cout << second.getName() << " wins!" << std::endl;
            return;
        }

        turn++;
    }
}