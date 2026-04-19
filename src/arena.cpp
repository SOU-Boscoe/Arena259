#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include "arena.h"

void Arena::battle(Creature &a, Creature &b)
{
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

void Arena::tournament(Creature&a, Creature&b, Creature&c, Creature&d,
                       Creature&e, Creature&f, Creature&g, Creature&h){
    std::vector<Creature*> fighters = { &a, &b, &c, &d, &e, &f, &g, &h };

    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(fighters.begin(), fighters.end(), gen);

    std::cout << "---------------------------------\n";
    std::cout << "--- The tournament has begun! ---\n";
    std::cout << "---------------------------------\n\n";

    while (fighters.size() > 1){
        std::vector<Creature*> winners;

        for (size_t i = 0; i < fighters.size(); i +=2){
            Creature* c1 = fighters[i];
            Creature* c2 = fighters[i+1];
            int hlthval1 = c1->health;
            int hlthval2 = c2->health;
            battle(*c1, *c2);

            if (c1->isAlive()){
                winners.push_back(c1);
                c1->health = hlthval1;
            }
            else{
                winners.push_back(c2);
                c2->health = hlthval2;
            }
            std::cout << "---------------------------------\n\n";
        }
        fighters = winners;
    }
    std::cout << "---------------------------------\n";
    std::cout << "--- The tournament has ended! ---\n";
    std::cout << "---------------------------------\n\n";
    std::cout << "- The tournament champion is: " << fighters[0]->name << "! -\n";
    return;
}