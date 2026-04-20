#include <iostream>
#include <iomanip>
#include "arena.h"

void Arena::battle(Creature &a, Creature &b)
{
    std::cout << "=============================\n";
    std::cout << "        ARENA BATTLE        \n";
    std::cout << "=============================\n";

    std::cout << a.name << " vs " << b.name << "\n\n";

    int turn = 1;

    while (a.isAlive() && b.isAlive())
    {
        std::cout << "-----------------------------\n";
        std::cout << "Turn " << turn << "\n";
        std::cout << "-----------------------------\n";

        std::cout << std::left
                  << std::setw(10) << a.name << " HP: " << a.health << "\n"
                  << std::setw(10) << b.name << " HP: " << b.health << "\n\n";

        std::cout << a.name << " attacks " << b.name << "\n";
        a.attack(b);

        std::cout << b.name << " HP is now " << b.health << "\n";

        if (!b.isAlive())
        {
            std::cout << "\n" << b.name << " has died\n";
            break;
        }

        std::cout << "\n" << b.name << " attacks back at " << a.name << "\n";
        b.attack(a);

        std::cout << a.name << " HP is now " << a.health << "\n";

        if (!a.isAlive())
        {
            std::cout << "\n" << a.name << " has died :(\n";
            break;
        }

        turn++;
    }

    std::cout << "\n=============================\n";
    if (a.isAlive())
    {
        std::cout << a.name << " WINS XD\n";
    }
    else
    {
        std::cout << b.name << " WINS :D\n";
    }
    std::cout << "=============================\n";
}
