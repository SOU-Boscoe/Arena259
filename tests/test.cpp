#include <iostream>

#include "../src/creature.h"
#include "../src/creatures/devil.h"
#include "../src/creatures/giantleech.h"

using namespace std;

int main()
{
    // create creatures
    LordDevilious devil;

    Creature leech = makeGiantleech();

    // show starting health
    cout << devil.getName()
         << " HP: "
         << devil.getHealth()
         << endl;

    cout << leech.getName()
         << " HP: "
         << leech.getHealth()
         << endl;

    cout << "\nSPECIAL MOVE!\n" << endl;

    // use special move
    devil.specialMove(leech);

    // show result
    cout << "\nAfter attack:\n";

    cout << devil.getName()
         << " HP: "
         << devil.getHealth()
         << endl;

    cout << leech.getName()
         << " HP: "
         << leech.getHealth()
         << endl;

    return 0;
}