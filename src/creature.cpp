

#include "creature.h"

// static variable
int Creature::creatureCount = 0;

// constructor
Creature::Creature(std::string n, int h, int d)
    : name(n), health(h), damage(d)
{
    creatureCount++;
}

// getters
std::string Creature::getName() const
{
    return name;
}

int Creature::getHealth() const
{
    return health;
}

int Creature::getDamage() const
{
    return damage;
}

int Creature::getCreatureCount()
{
    return creatureCount;
}

// behavior
void Creature::takeDamage(int dmg)
{
    health -= dmg;
    if (health < 0)
        health = 0;
}

void Creature::attack(Creature &other)
{
    other.takeDamage(damage);

    // Giant Leech heals after attacking because leeches drain life
    if (name == "Giant Leech")
    {
        health += 5;

        if (health > MAX_HEALTH)
        {
            health = MAX_HEALTH;
        }
    }
}

bool Creature::isAlive() const
{
    return health > 0;
}

// validation
bool Creature::validate(Creature &c)
{
    if (c.health < MIN_HEALTH || c.health > MAX_HEALTH)
    {
        std::cerr << "Error: " << c.name << " has invalid health." << std::endl;
        return false;
    }

    if (c.damage <= 0 || c.damage > 20)
    {
        std::cerr << "Error: " << c.name << " has invalid damage." << std::endl;
        return false;
    }

    return true;
}

bool Creature::validateBattle(Creature &a, Creature &b)
{
    if (!validate(a) || !validate(b))
    {
        std::cerr << "The Battle cannot take place." << std::endl;
        return false;
    }
    return true;
}