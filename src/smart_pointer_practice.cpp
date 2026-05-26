#include <iostream>
#include <memory>
#include <vector>
#include "creature.h"
#include "jeff.h"

//Overrides the battle function in arena.
void battle(Creature& a, Creature& b){
    a.attack(b);
    b.specialMove(a);
}

int main(){
    //Creates a unique pointer called fighter of a Jeff object.
    std::unique_ptr<Creature> fighter = std::make_unique<Jeff>("jeff", 100, 5);

    //Creates another jeff object for the unique pointer to fight
    Jeff jeff("jeff", 100, 5);
    //The unique pointer uses specialMove on the second jeff object.
    fighter->specialMove(jeff);

    //Creates a vector and inserts two Jeff unique pointers into it.
    std::vector<std::unique_ptr<Creature>> fighters;
    fighters.push_back(std::make_unique<Jeff>("jeff1", 100, 5));
    fighters.push_back(std::make_unique<Jeff>("jeff2", 100, 5));
    
    //runs a for loop for every Jeff unique pointer contained in the vector fighters.
    //It gets each Jeff objects name.
    for (auto& fighter : fighters){
        std::cout << fighter->getName() << std::endl;
    }

    //Commences a battle between the first and second unique pointer in the fighters vector.
    battle(*fighters[0], *fighters[1]);


    return 0;
}