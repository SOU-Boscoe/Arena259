#include <iostream>
#include "utils.h"
#include "arena.h"

bool Arena::takeTurn(Creature &acting, Creature &target) 
    /// @brief Abstracts the turn logic into a function to prevent code duplication across nested conditionals going forward.
    /// @param acting Reference to the creature instance that is acting on the current turn
    /// @param target Reference to the acting creature's target
    /// @return returns the inverse of target.isAlive() to pass into the while loop condition hasWinner. 
    /// @return The truth tables of these values are semantically opposed and should be unified eventually.

{
    std::cout << acting.name << " attacks for " << Color::YELLOW << acting.damage << Color::RESET << std::endl;
    acting.attack(target);
    std::cout << target.name << " health: " << target.health << std::endl;

    return !target.isAlive();
}


void Arena::battle(Creature &a, Creature &b)
/// @brief Runs the primary loop for Arena battles.
/// @param a Reference to an instance of Creature
/// @param b Reference to an instance of Creature
{
    /// Wrap the creature names with color values and store them to
    /// make the output more readable and fun!
    a.name = colorMe(a.name, Color::BLUE);
    b.name = colorMe(b.name, Color::GREEN);

    std::cout << "\n================================\n";
    std::cout << a.name << " vs " << b.name << std::endl;
    std::cout << "================================";

    int turn = 1;

    /// set hasWinner to false before the while loop
    /// if takeTurn returns true, we break the loop and
    /// announce the winner.
    bool hasWinner = false;

    while (!hasWinner) /// Primary game loop
    {
        /// Announce turn number and then flip a coin to se
        /// which creature goes first.
        std::cout << "\nTurn " << turn << std::endl;
        if (flipCoin()) {
            /// optional statement for debugging to show who won the coin toss
            // std::cout << "Heads! " << b.name << " goes first!" << std::endl; 

            hasWinner = takeTurn(b, a); if (hasWinner) {break;}
            hasWinner = takeTurn(a, b); if (hasWinner) {break;}
        }

        else {
            /// optional statement for debugging to show who won the coin toss
            // std::cout << "Tails! " << a.name << " goes first!" << std::endl;

            hasWinner = takeTurn(a, b); if (hasWinner) {break;}
            hasWinner = takeTurn(b, a); if (hasWinner) {break;}
        }

        turn++;
    }


    /// When the while loop breaks, we need to check to 
    /// see which creature is still alive and announce 
    /// them as the winner.
    if (a.isAlive())
    {
        std::cout << "\n================================\n";
        std::cout << a.name << " wins!" << std::endl;
        std::cout << "================================\n\n";
    }
    else
    {
        std::cout << "\n================================\n";
        std::cout << b.name << " wins!" << std::endl;
        std::cout << "================================\n\n";
    }
}