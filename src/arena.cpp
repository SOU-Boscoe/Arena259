#include <iostream>
#include "arena.h"

// Checks to see if creature has a valid health and valid damage value
bool validate(Creature &c){
    if(c.health <= 0){
        std::cerr << "Error: " << c.name << " has invalid health. Health must be > 0" << std::endl;
        return false;
    }
    if(c.damage <= 0){
        std::cerr << "Error: " << c.name << " has invalid damage. Damage must be > 0" << std::endl;
        return false;
    }
    return true;
}

void Arena::battle(Creature &a, Creature &b)
{
    /* 
    If Creature a or b does not have the valid stats for health or damage
    It will output an error message and abort
    */
    if(!validate(a) || !validate(b)){
        std::cerr << "The Battle cannot take place as there are invalid stats" << std::endl;
        return;
    }

    std::cout << a.name << " vs " << b.name << std::endl;

    int turn = 1;

    while (a.isAlive() && b.isAlive())
    {
        std::cout << "\nTurn " << turn << std::endl;

        std::cout << a.name << " attacks!" << std::endl;
        a.attack(b);
        std::cout << b.name << " health: " << b.health << std::endl;

        if (!b.isAlive())
            break;

        std::cout << b.name << " attacks!" << std::endl;
        b.attack(a);
        std::cout << a.name << " health: " << a.health << std::endl;

        turn++;
    }

    if (a.isAlive())
    {
        std::cout << a.name << " wins!" << std::endl;
    }
    else
    {
        std::cout << b.name << " wins!" << std::endl;
    }
}