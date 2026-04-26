#include <iostream>
#include "arena.h"

void Arena::battle(Creature &a, Creature &b)
{

    if(!Creature::validateBattle(a, b)){
        return;
    }
    
    // Changing all these from name / health to getName / getHealth
    std::cout << a.getName() << " vs " << b.getName() << std::endl;

    int turn = 1;

    while (a.isAlive() && b.isAlive())
    {
        std::cout << "\nTurn " << turn << std::endl;

        std::cout << a.getName() << " attacks!" << std::endl;
        a.attack(b);
        std::cout << b.getName() << " health: " << b.getHealth() << "\tdefense: " << b.getDefense() << std::endl;

        if (!b.isAlive())
            break;

        std::cout << b.getName() << " attacks!" << std::endl;
        b.attack(a);
        std::cout << a.getName() << " health: " << a.getHealth() << "\tdefense: " << a.getDefense() << std::endl;

        turn++;
    }

    if (a.isAlive())
    {
        std::cout << a.getName() << " wins!" << std::endl;
    }
    else
    {
        std::cout << b.getName() << " wins!" << std::endl;
    }
}