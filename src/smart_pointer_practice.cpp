#include "creature.h"
#include "creatures/grumpywizard.h"
#include "creatures/abominablemudman.h"
#include <vector>
#include <memory>

using namespace std;

void battle(Creature& a, Creature& b) {
    a.attack(b);
    b.attack(a);
    a.specialMove(b);
    b.specialMove(a);
}

int main() {

    unique_ptr<Creature> grumpy = make_unique<GrumpyWizard>();
    AbominableMudman mudman;

    grumpy->specialMove(mudman);

    vector<unique_ptr<Creature>> creatures;

    creatures.push_back(make_unique<GrumpyWizard>());
    creatures.push_back(make_unique<AbominableMudman>());

    
    for (auto& c : creatures) {
        cout << c->getName() << endl;
    }

    battle(*creatures[0], *creatures[1]);


                                
    return 0;
}