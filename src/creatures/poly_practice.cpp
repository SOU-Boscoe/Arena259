#include <iostream>
#include "../creature.h"
#include "clawdragon.h"
#include "darkjellyfish.h"

void doSpecial(Creature* attacker, Creature& target){
        attacker->specialMove(target);
}

int main(){

    

    Clawdragon dragon;
    DarkJellyfish goblin;

    Creature* fighter = &dragon;
    fighter->specialMove(goblin);

    Creature* fighters[2];
    fighters[0] = &dragon;
    fighters[1] = &goblin;

    for(int i = 0; i < 2; i++){
        fighters[i]->specialMove(dragon);
    }

   

    return 0;
}