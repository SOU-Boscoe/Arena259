#include <iostream>
#include <memory>
#include <vector>

#include "../src/creature.h"
#include "../src/creatures/devil.h"

using namespace std;

// Small battle test using references.
// The * from unique_ptr will give us the real creature object.
void battle(Creature& a, Creature& b)
{
    cout << "\nMini Battle\n";
    cout << a.getName() << " attacks " << b.getName() << endl;
    a.attack(b);

    cout << b.getName() << " uses special move on " << a.getName() << endl;
    b.specialMove(a);

    cout << a.getName() << " HP: " << a.getHealth() << endl;
    cout << b.getName() << " HP: " << b.getHealth() << endl;
}

int main()
{
    // unique_ptr owns the creature and cleans it up automatically.
    unique_ptr<Creature> fighter = make_unique<LordDevilious>();

    Creature target("Training Dummy", 100, 5);

    cout << fighter->getName() << " uses a special move.\n";
    fighter->specialMove(target);

    cout << target.getName() << " HP: " << target.getHealth() << endl;

    // Vector can hold different creature types through Creature pointers.
    vector<unique_ptr<Creature>> fighters;

    fighters.push_back(make_unique<LordDevilious>());
    fighters.push_back(make_unique<Creature>("Goblin", 80, 12));

    cout << "\nFighters:\n";
    for (auto& creature : fighters)
    {
        cout << creature->getName() << endl;
    }

    battle(*fighters[0], *fighters[1]);

    return 0;
}