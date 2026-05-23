#include <iostream>
#include <memory>
#include "../src/creature.h"
#include "../src/creatures/abominablemudman.h"
#include "../src/creatures/devil.h"

void battle(Creature& a, Creature& b) {
    int turn = 1;
    while(a.isAlive() && b.isAlive()){
        if (turn%8 == 0){ //every seven turns performs special move
            std::cout << a.getName() << " performs specialMove:\n";
            a.specialMove(b);
            std::cout << b.getName() << "health: " << b.getHealth() << "\n";
        }
        if (turn%8 == 1 && turn > 1){ //every seven turns +1 performs special move
            std::cout << b.getName() << " performs specialMove:\n";
            b.specialMove(a);
            std::cout<< a.getName() << "health: " << a.getHealth() << "\n";

        }
        else{
            if(turn % 2 == 0){// every other turn performs attack
            std::cout << a.getName() << " performs attack:\n";
            a.attack(b);
            std::cout << b.getName() << "health: " << b.getHealth() << "\n";
            }
            else{ // every other turn +1 performs attack
                std::cout << b.getName() << " performs attack:\n";
                b.attack(a);
                std::cout << a.getName() << "health: " << a.getHealth() << "\n";
            }
        }
        turn++;
    }

    if (!a.isAlive() && !b.isAlive()){ //signals a tie (probably impossible unless self damage)
        std::cout << "Its a draw!\n";
    }
    if (a.isAlive()){
        std::cout << a.getName() << " has won the battle!\n";
    }

    if (b.isAlive()){
        std::cout << b.getName() << " has won the battle!\n";
    }


}

int main() {

    std::cout << "\nTesting specialMove using smart ptr:\n\n";
    std::unique_ptr<Creature> fighter1 =
        std::make_unique<AbominableMudman>();

    LordDevilious fighter2;
    fighter1->specialMove(fighter2);

    std::cout << "\nTesting vector holding creatures using smart ptr:\n\n";
    std::vector<std::unique_ptr<Creature>> fighters;
    fighters.push_back(std::make_unique<AbominableMudman>());
    fighters.push_back(std::make_unique<LordDevilious>());

    for (auto& fighter : fighters) {
        std::cout << fighter->getName() << std::endl;
    }

    std::cout << "\nTesting battle using smart ptr:\n\n";
    battle(*fighters[0], *fighters[1]);

    return 0;
}



