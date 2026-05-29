#include <iostream>
#include <iomanip>
#include <algorithm>
#include "arena.h"
#include "rng.h"

Arena::Arena(){
    std::vector<std::unique_ptr<Creature>> newfighters;
    fighters = std::move(newfighters);
}
Arena::Arena(std::vector<std::unique_ptr<Creature>>& newfighters){
    fighters = std::move(newfighters);
}

void Arena::battle(Creature &temp1, Creature &temp2)
{
    std::random_device rd;
    std::mt19937 gen(rd());

    Creature* first;
    Creature* second;

    std::uniform_int_distribution<> specialTurnDist(3, 6);

    int c1SpecialTurn = specialTurnDist(gen);
    int c2SpecialTurn = specialTurnDist(gen);

    bool c1UsedSpecial = false;
    bool c2UsedSpecial = false;

    if (RNG::flipCoin() == 1) {
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
    
    std::cout << a.getName() << " vs " << b.getName() << std::endl;

    int turn = 1;

    while (a.isAlive() && b.isAlive()){
    
        {
            std::cout << "\n-----------------------------\n";
            std::cout << "Turn " << turn << std::endl;  
            std::cout << "-----------------------------\n";


            std::cout << std::left
                      << std::setw(10) << a.getName() << " HP: " << a.getHealth() << "\n"
                      << std::setw(10) << b.getName() << " HP: " << b.getHealth() << "\n";


            if (!c1UsedSpecial && turn == c1SpecialTurn) {

                std::cout << a.getName()
                          << " uses SPECIAL MOVE!\n";

                a.specialMove(b);
                c1UsedSpecial = true;
            }
            else {
                std::cout << a.getName() << " attacks!" << std::endl;
                a.attack(b);
                std::cout << b.getName() << " health: " << b.getHealth() << std::endl;
            }

            if (!c2UsedSpecial && turn == c2SpecialTurn) {

                std::cout << b.getName()
                          << " uses SPECIAL MOVE!\n";

                b.specialMove(a);
                c2UsedSpecial = true;
            }
            else{
                std::cout << b.getName() << " attacks!" << std::endl;
                b.attack(a);
                std::cout << a.getName() << " health: " << a.getHealth() << std::endl;
            }
            turn++;
        }
    }

    // Ezra's custom battle statistics code    
    // print out battle stats
    std::cout << std::endl;
    printStats(a, b, turn);
}

void Arena::tournament() {

    std::random_device rd;
    std::mt19937 gen(rd());

    std::shuffle(fighters.begin(), fighters.end(), gen);

    std::cout << "---------------------------------\n";
    std::cout << "--- The tournament has begun! ---\n";
    std::cout << "---------------------------------\n\n";

    int heat = 1;

    while (fighters.size() > 1) {
        std::cout << "========== HEAT "
                  << heat
                  << " ==========\n\n";

        std::vector<std::unique_ptr<Creature>> winners;

        for (size_t i = 0; i < fighters.size(); i += 2) {
            // Odd number of fighters automatic advancement
            if (i + 1 >= fighters.size()) {

                std::cout << fighters[i]->getName()
                          << " advances automatically!\n\n";

                winners.push_back(std::move(fighters[i]));
                continue;
            }

            Creature& c1 = *fighters[i];
            Creature& c2 = *fighters[i + 1];

            int c1Health = c1.getHealth();
            int c2Health = c2.getHealth();

            battle(c1, c2);

            if (c1.isAlive()) {

                c1.setHealth(c1Health);
                winners.push_back(std::move(fighters[i]));
            }
            else {

                c2.setHealth(c2Health);
                winners.push_back(std::move(fighters[i + 1]));
            }

            std::cout << "---------------------------------\n\n";
        }

        fighters = std::move(winners);
        heat++;
    }

    std::cout << "---------------------------------\n";
    std::cout << "--- The tournament has ended! ---\n";
    std::cout << "---------------------------------\n\n";

    std::cout << "- The tournament champion is: "
              << fighters[0]->getName()
              << "! -\n";
}

void Arena::printStats(Creature& a, Creature& b, int turns) {

    // print winner
    std::cout << "Battle finished, the winner is ";
    if (a.isAlive())
    {
        std::cout << a.getName() << "!" << std::endl;
    }
    else
    {
        std::cout << b.getName() << "!" << std::endl;
    }

    // arena stats
    std::cout << "Total turns: " << turns << std::endl;
    std::cout << "Total Damage Dealt: " << a.getDamageDealt() + b.getDamageDealt() << std::endl;
    std::cout << std::endl;

    // a creature stats
    std::cout << a.getName() << " Health: " << a.getHealth() << "/" << a.getStartHealth() << std::endl;
    std::cout << a.getName() << " Damage Dealt: " << a.getDamageDealt() << std::endl;
    std::cout << std::endl;

    // b creature stats
    std::cout << b.getName() << " Health: " << b.getHealth() << "/" << b.getStartHealth() << std::endl;
    std::cout << b.getName() << " Damage Dealt: " << b.getDamageDealt() << std::endl;

}

void Arena::addFighter(std::unique_ptr<Creature> fighter){
    fighters.push_back(std::move(fighter));
    std::cout << "Arena now has " << fighters.size() << " fighters\n";
}

void Arena::indexBattle(int first, int second){
    battle(*fighters[first], *fighters[second]);
}
