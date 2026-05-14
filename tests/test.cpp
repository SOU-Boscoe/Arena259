#include "../src/creatures/dragon.h"

int main(){
    Dragon dragon;
    Creature goblin("Goblin", 50, 8);
    dragon.attack(goblin);

    dragon.specialMove(goblin);
    return 0;
}
