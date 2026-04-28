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

    //Broken with removal of the function in the creature file
    //if(!Creature::validateBattle(a, b)){
    //    return;
    //}
	    
    std::cout << "=============================\n";
    std::cout << "        ARENA BATTLE        \n";
    std::cout << "=============================\n";

    //outputs the names of the creatures.
    std::cout << a.getName() << " vs " << b.getName() << std::endl;

    int turn = 1;

    //continues the battle until one creature's isAlive funciton is false.
    while (Creature::isAlive(a) && Creature::isAlive(b)){
    std::cout << "\n-----------------------------\n";
	std::cout << "Turn " << turn << std::endl;
	std::cout << "-----------------------------\n";


    //outputs stats per turn.
	std::cout << std::left
                  << std::setw(10) << a.getName() << " HP: " << a.getHealth() << "\n"
                  << std::setw(10) << b.getName() << " HP: " << b.getHealth() << "\n";


        //Creature a attacks creature b and modifies b's stats accordingly.
        std::cout << a.getName() << " with attack power "<< a.getDamage() << " attacks " << b.getName() << "!" << std::endl;
        int temp_attack_a = a.attack();
        b.takeDamage(temp_attack_a);
        std::cout << b.getName() << " health is: " << b.getHealth() << " HP" << std::endl;

        //Creature b attacks creature a and modifies a's stats accordingly.
        std::cout << b.getName() << " with attack power " << b.getDamage() << " attacks " << a.getName() << "!" << std::endl;
        int temp_attack_b = b.attack();
        a.takeDamage(temp_attack_b);
        std::cout << a.getName() << " health is: " << a.getHealth() << " HP" << std::endl;

        turn++;
    }

    //checks which creature has died and outputs a victor.
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
