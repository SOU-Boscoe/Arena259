#include <iostream>
#include "arena.h"
#include <cstdlib>

void Arena::battle(Creature &a, Creature &b)
{

    if(!Creature::validateBattle(a, b)){
        return;
    }
    
    std::cout << a.name << " vs " << b.name << std::endl;

    int turn = 1;

    while (a.isAlive() && b.isAlive())
    {
        std::cout << "\nTurn " << turn << std::endl;

        std::cout << a.name << " attacks!" << std::endl;

        int hitA = a.damage + (std::rand() % 3 - 1);
        if (hitA < 0) hitA = 0;

        b.health -= hitA;
        if (b.health < 0) b.health = 0;

        std::cout << a.name << " deals " << hitA << " damage!" << std::endl;
        std::cout << b.name << " health: " << b.health << std::endl;

        if (!b.isAlive())
            break;

        std::cout << b.name << " attacks!" << std::endl;

        int hitB = b.damage + (std::rand() % 3 - 1);
        if (hitB < 0) hitB = 0;

        a.health -= hitB;
        if (a.health < 0) a.health = 0;

        std::cout << b.name << " deals " << hitB << " damage!" << std::endl;
        std::cout << a.name << " health: " << a.health << std::endl;

        turn++;
    }

    if (a.isAlive())
        std::cout << a.name << " wins!" << std::endl;
    else
        std::cout << b.name << " wins!" << std::endl;
}