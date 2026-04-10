#include "arena.h"
#include "creature.h"
#include <iostream>

int main(int argc, char* argv[]) {

    // count args and either run default creatures
    // or find creatures by argv.
    if (argc == 1) {
        Arena arena;
        Imp imp;
        Cherub cherub;

        arena.battle(imp, cherub);
    }

    else {
        std::cout << "* * * Creature factory not yet implemented. Try again later. * * *" << std::endl;
    }

    return 0;
}