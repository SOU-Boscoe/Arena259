#ifndef CREATURE_H
#define CREATURE_H

#include <string>
#include <iostream>

const int MIN_HEALTH = 80;
const int MAX_HEALTH = 120;

class Creature
{
private:
    std::string name;
    int health;
    int damage;

    static int creatureCount;

public:
    // constructor
    Creature(std::string n, int h, int d);

    // getters
    std::string getName() const;
    int getHealth() const;
    int getDamage() const;

    static int getCreatureCount();

    // behavior
    void takeDamage(int dmg);
    void attack(Creature &other);
    bool isAlive() const;

    // validation
    static bool validate(Creature &c);
    static bool validateBattle(Creature &a, Creature &b);
};

#endif