#include <iostream>
#include <iomanip>
#include "arena.h"
#include "arenarand.h"

void Arena::battle(Creature &temp1, Creature &temp2)
{

    Creature* first;
    Creature* second;

    if (ArenaRand::flipCoin() == 1) {
        first = &temp1;
        second = &temp2;
    } else {
        first = &temp2;
        second = &temp1;
    }

    Creature& a = *first;
    Creature& b = *second;

    if(!Creature::validateBattle(a, b)){
        return;
    }
	    
    std::cout << "=============================\n";
    std::cout << "        ARENA BATTLE        \n";
    std::cout << "=============================\n";

    std::cout << a.getName() << " vs " << b.getName() << std::endl;

    int turn = 1;

    while (a.isAlive() && b.isAlive())
    {
        std::cout << "\n-----------------------------\n";
	std::cout << "Turn " << turn << std::endl;
	std::cout << "-----------------------------\n";


	std::cout << std::left
                  << std::setw(10) << a.getName() << " HP: " << a.getHealth() << "\n"
                  << std::setw(10) << b.getName() << " HP: " << b.getHealth() << "\n";


        std::cout << a.getName() << " with attack power "<< a.getDamage() << " attacks " << b.getName() << "!" << std::endl;
        a.attack(b);
        std::cout << b.getName() << " getHealth() is: " << b.getHealth() << " HP" << std::endl;


        std::cout << b.getName() << " with attack power " << b.getDamage() << " attacks " << a.getName() << "!" << std::endl;
        b.attack(a);
        std::cout << a.getName() << " getHealth() is: " << a.getHealth() << " HP" << std::endl;

        turn++;
    }

    std::cout << "\n=============================\n";
    if (a.isAlive())
    {
        std::cout << a.getName() << " defeats " << b.getName() << "!" << std::endl;
        std::cout << a.getName() << " has " << a.getHealth() << " HP remaining." << std::endl;
    }
    else
    {
        std::cout << b.getName() << " defeats " << a.getName() << "!"<< std::endl;
        std::cout << b.getName() << " has " << b.getHealth() << " HP remaining." << std::endl;
    }
    std::cout << "=============================\n";
}
