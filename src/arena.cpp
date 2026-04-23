#include <iostream>
#include <iomanip>
#include "arena.h"

void Arena::battle(Creature &a, Creature &b)
{
    std::cout << a.name << " vs. " << b.name << std::endl;

    if(!Creature::validateBattle(a, b)){
        return;
    }

    std::cout << "=============================\n";
    std::cout << "        ARENA BATTLE        \n";
    std::cout << "=============================\n";

    std::cout << a.name << " vs " << b.name << std::endl;

    int turn = 1;

    while (a.isAlive() && b.isAlive())
    {
        std::cout << "-----------------------------\n";
	std::cout << "\nTurn " << turn << std::endl;
	std::cout << "-----------------------------\n";


	std::cout << std::left
                  << std::setw(10) << a.name << " HP: " << a.health << "\n"
                  << std::setw(10) << b.name << " HP: " << b.health << "\n";


        std::cout << a.name << " with attack power "<< a.damage << " attacks " << b.name << "!" << std::endl;
        a.attack(b);
        std::cout << b.name << " health is: " << b.health << " HP" << std::endl;


        std::cout << b.name << " with attack power " << b.damage << " attacks " << a.name << "!" << std::endl;
        b.attack(a);
        std::cout << a.name << " health is: " << a.health << " HP" << std::endl;

        turn++;
    }

    std::cout << "\n=============================\n";
    if (a.isAlive())
    {
        std::cout << a.name << " defeats " << b.name << "!" << std::endl;
        std::cout << a.name << " has " << a.health << " HP remaining." << std::endl;
    }
    else
    {
        std::cout << b.name << " defeats " << a.name << "!"<< std::endl;
        std::cout << b.name << " has " << b.health << " HP remaining." << std::endl;

        std::cout << "\n=============================\n";
    }
}

/*
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
*/

