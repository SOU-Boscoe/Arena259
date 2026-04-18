#include <iostream>
#include <vector>
#include "arena.h"
#include "creature.h"
#include <cstdlib>
#include <ctime>
#include "viper.h"
#include "segoblin.h"
#include "giantleech.h"

using namespace std;




int main()
{
    srand(time(0)); // begins randomness

    vector<Creature> creatures;
    // Create some creatures
    creatures.push_back(makeViper());
    creatures.push_back(makeSEGoblin());
    creatures.push_back(makeGiantleech());

    return 0;

int turn = 1;

// loop until 1 creature left alive
while (true)
    {
        cout << "\nTurn " << turn << endl;

        int aliveCount = 0;

        // count living creatures
        for (int i = 0; i < creatures.size(); i++)
        {
            if (creatures[i].isAlive())
            {
                aliveCount++;
            }
        }

        // stop if only 1 is left
        if (aliveCount <= 1)
        {
            break;
        }

        int attackerIndex;

        // find random living attacker
        do
        {
            attackerIndex = rand() % creatures.size();
        }
        while (!creatures[attackerIndex].isAlive());

        int targetIndex;

        // find random living target that is not the attacker
        do
        {
            targetIndex = rand() % creatures.size();
        }
        while (targetIndex == attackerIndex || !creatures[targetIndex].isAlive());

        // attack target
        cout << creatures[attackerIndex].name << " attacks "
             << creatures[targetIndex].name << endl;

        creatures[attackerIndex].attack(creatures[targetIndex]);

        cout << creatures[targetIndex].name << " health: "
             << creatures[targetIndex].health << endl;

        turn++;
    }

    // print winner
    for (int i = 0; i < creatures.size(); i++)
    {
        if (creatures[i].isAlive())
        {
            cout << "\nWinner, Winner Chicken Dinner! " << creatures[i].name << endl;
        }
    }

    return 0;
}

