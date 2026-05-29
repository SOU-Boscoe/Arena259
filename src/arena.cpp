#include <iostream>
#include <iomanip>
#include <algorithm>
#include "utils.h"
#include "arena.h"
#include "rng.h"

// Removes conditional/duplicate print statements when a winner is decided
void Arena::printWinner(Creature& winner) {
    std::cout << Color::YELLOW << "\n=============================\n" << Color::RESET;
    std::cout << colorMe(winner.getName(), Color::GREEN) << " wins!\n";
    std::cout << colorMe(winner.getName(), Color::GREEN) << " has "
              << colorMe(std::to_string(winner.getHealth()), Color::GREEN) << " HP remaining.\n";
    std::cout << Color::YELLOW << "=============================\n" << Color::RESET;
}

void Arena::printBegin() {
    std::cout << Color::YELLOW << "=============================\n";
    std::cout << "        ARENA BATTLE        \n";
    std::cout << "=============================\n" << Color::RESET;
    for (auto& c : creatures) {
        std::cout << "  " << colorMe(c->getName(), Color::CYAN)
                  << " (" << colorMe(std::to_string(c->getHealth()), Color::GREEN) << " HP)\n";
    }
    std::cout << Color::YELLOW << "=============================\n" << Color::RESET;
}

void Arena::printTurn(int turn) {
    std::cout << Color::BLUE << "\n-----------------------------\n";
    std::cout << "Turn " << turn << "\n";
    std::cout << "-----------------------------\n" << Color::RESET;
}

bool Arena::takeTurn(Creature& acting, Creature& target) {
    if (RNG::randomValue(1, acting.specialChance()) == acting.specialChance()) {
        acting.specialMove(target);
        std::cout << acting.getName() << " uses SPECIAL MOVE!\n";
    }
    else { acting.attack(target); }
    return target.isAlive();
}

bool Arena::checkPulse(const Creature c) {
    if (&c == nullptr) { return false; };
    return c.isAlive();
}

bool Arena::validateBattle(Creatures creatures) {
    std::string error = "The stats of the creatures are invalid, so the battle cannot take place.";
    if (creatures.size() < 2) {
        for (const auto& c : creatures) {
            if (!Creature::isValid(*c)) {
                std::cerr << error << std::endl;
                return false;
            }
        }
        return true;
    }
}

void Arena::battleRoyale()
{
    int turn = 1;
// must use a non-owning structure because unique_ptr is not copyable.
    std::vector<Creature*> still_alive;

    printBegin();

    hasWinner = false;
    
    while (!hasWinner)
    {
        printTurn(turn);
        for (auto& c : creatures)
        {
            if (!checkPulse(*c)) continue;
            std::cout << "\n>> " << colorMe(c->getName() + "'s", Color::CYAN) << " turn:\n";
            Creature& target = c->chooseTarget(creatures);
            bool survived = takeTurn(*c, target);
            if (!survived) {
                std::cout << colorMe("** " + target.getName() + " has been defeated! **", Color::RED) << "\n";
            }
        }
        turn++;

        still_alive.clear();
        for (auto& c: creatures)
        {
            if (checkPulse(*c)) { still_alive.push_back(&(*c)); }
        }
        if (still_alive.size() == 1) {
            printWinner(*still_alive[0]);
            hasWinner = true;
        }
    }
}

void Arena::battle()
{
    auto& a = creatures[0];
    auto& b = creatures[1];

    if (RNG::flipCoin() == 1) { std::swap(a, b); }

    if(!Arena::validateBattle(creatures)){ return; }

    std::cout << a->getName() << " vs " << b->getName() << std::endl;

    hasWinner = false;

    int turn = 1;

    while (!hasWinner){

        {
            printTurn(turn);            
            if (!takeTurn(*a, *b)) { hasWinner = true; break; }
            if (!takeTurn(*b, *a)) { hasWinner = true; break; }

            turn++;
        }
    }

    // printStats(a, b, turn);
}

void Arena::tournament() {

    std::shuffle(creatures.begin(), creatures.end(), RNG::gen);

    std::cout << "---------------------------------\n";
    std::cout << "--- The tournament has begun! ---\n";
    std::cout << "---------------------------------\n\n";

    int heat = 1;

    while (creatures.size() > 1) {
        std::cout << "========== HEAT "
                  << heat
                  << " ==========\n\n";

        Creatures winners;

        for (size_t i = 0; i < creatures.size(); i += 2) {
            // Odd number of creatures automatic advancement
            if (i + 1 >= creatures.size()) {

                std::cout << creatures[i]->getName()
                          << " advances automatically!\n\n";

                winners.push_back(std::move(creatures[i]));
                continue;
            }

            Creature& c1 = *creatures[i];
            Creature& c2 = *creatures[i + 1];

            int c1Health = c1.getHealth();
            int c2Health = c2.getHealth();

            battle();

            if (c1.isAlive()) {

                c1.setHealth(c1Health);
                winners.push_back(std::move(creatures[i]));
            }
            else {

                c2.setHealth(c2Health);
                winners.push_back(std::move(creatures[i + 1]));
            }

            std::cout << "---------------------------------\n\n";
        }

        creatures = std::move(winners);
        heat++;
    }

    std::cout << "---------------------------------\n";
    std::cout << "--- The tournament has ended! ---\n";
    std::cout << "---------------------------------\n\n";

    std::cout << "- The tournament champion is: "
              << creatures[0]->getName()
              << "! -\n";
}

// void Arena::printStats(Creature& a, Creature& b, int turns) {

//     // print winner
//     std::cout << "Battle finished, the winner is ";
//     if (a->isAlive())
//     {
//         std::cout << a->getName() << "!" << std::endl;
//     }
//     else
//     {
//         std::cout << b->getName() << "!" << std::endl;
//     }

//     // arena stats
//     std::cout << "Total turns: " << turns << std::endl;
//     std::cout << "Total Damage Dealt: " << a->getDamageDealt() + b->getDamageDealt() << std::endl;
//     std::cout << std::endl;

//     // a creature stats
//     std::cout << a->getName() << " Health: " << a->getHealth() << "/" << a->getStartHealth() << std::endl;
//     std::cout << a->getName() << " Damage Dealt: " << a->getDamageDealt() << std::endl;
//     std::cout << std::endl;

//     // b creature stats
//     std::cout << b->getName() << " Health: " << b->getHealth() << "/" << b->getStartHealth() << std::endl;
//     std::cout << b->getName() << " Damage Dealt: " << b->getDamageDealt() << std::endl;

// }
