#ifndef CREATURE_H
#define CREATURE_H

#include <string>

class Creature
{
private:
    std::string name;
    int health;
    int damage;
    int defense;

    static int creatureCount;

public:
    // Constructor
    Creature(const std::string& n, int h, int d, int def);
    Creature(const std::string& n, int h, int d);

    // Getters (const)
    std::string getName() const;
    int getHealth() const;
    int getDamage() const;
    int getDefense() const;

    // Static
    static int getCreatureCount();

    // Behavior
    bool isAlive() const;
    void takeDamage(int amount);
    void attack(Creature &other);

    // Validation
    static bool validate(const Creature &c);
    static bool validateBattle(const Creature &a, const Creature &b);
};

#endif
