#ifndef CREATURE_H
#define CREATURE_H

#include <string>
#include <iostream>

// Added many new initialized constants to set parameters for creature stats.
const int MIN_HEALTH = 80;
const int MAX_HEALTH = 120;
const int MIN_DAMAGE = 1;
const int MAX_DAMAGE = 20;
const int MIN_DEFENSE = 0;
const int MAX_DEFENSE = 10;
const int MIN_HEALING = 0;
const int MAX_HEALING = 20;

class Creature
{

// Created private member variables including one static variable for use across all creature class members.
private:
    std::string name;
    int maxHealth;
    int health;
    int damage;
    int defense;
    int healing;
    static int creatureCount;

// Added public member methods methods.
public:
    // Instantiates a Creature constructor method with five parameters.
    Creature(std::string n, int h, int d, int def, int heal)
        : name(n), maxHealth(h), health(h), damage(d), defense(def), healing(heal)
    {
        creatureCount++;
    }
    
    // Created getter methods to access all private memebr variables.
    std::string getName() const { return name; }
    int getMaxHealth() const { return maxHealth; }
    int getHealth() const { return health; }
    int getDamage() const { return damage; }
    int getDefense() const { return defense; }
    int getHealing() const { return healing; }

    // Added methods for taking damage, healing (a new, special method), and attacking.
    void takeDamage(int amount)
    {
        int actualDamage = amount - defense; // Calculates actual damge as a subtraction of defense from orther damage.
        if (actualDamage > 0) {
            health -= actualDamage;
            if (health < 0) {
                health = 0;
            }
        }
    }

    // Gives creatures a chance to heal themselves. Need areana rules to set implementation bounds.
    void heal()
    {
        health += healing;
        if (health > maxHealth) {
            health = maxHealth;
        }
    }

    // Creates attack method.
    void attack(Creature &other)
    {
        other.takeDamage(damage); // Directs attacks against opponents in areana.
    }

    // Cheacks if creature is alive.
    bool isAlive() const
    {
        return health > 0;
    }

    // Returns total creatures created using static private variable.
    static int getCreatureCount() { return creatureCount; }

    // Validation method checking creatures using new methods. Justifies creation of new global constanst variables above.
    static bool validate(const Creature &c){
        if(c.health < MIN_HEALTH || c.health > MAX_HEALTH){
            std::cerr << "Error: " << c.getName() << " has invalid health. Health must be between " << MIN_HEALTH << " and " << MAX_HEALTH << std::endl;
            return false;
        }
        if(c.damage < MIN_DAMAGE || c.damage > MAX_DAMAGE){
            std::cerr << "Error: " << c.getName() << " has invalid damage. Damage must be between " << MIN_DAMAGE << " and " << MAX_DAMAGE << std::endl;
            return false;
        }
        if(c.defense < MIN_DEFENSE || c.defense > MAX_DEFENSE){
            std::cerr << "Error: " << c.getName() << " has invalid defense. Defense must be between " << MIN_DEFENSE << " and " << MAX_DEFENSE << std::endl;
            return false;
        }
        if(c.healing < MIN_HEALING || c.healing > MAX_HEALING){
            std::cerr << "Error: " << c.getName() << " has invalid healing. Healing must be between " << MIN_HEALING << " and " << MAX_HEALING << std::endl;
            return false;
        }
        return true;
    }

    /*
    If Creature a or b does not have the valid stats for health or damage
    It will output an error message and abort
    */
    static bool validateBattle(const Creature &a, const Creature &b){
        if(!validate(a) || !validate(b)){
            std::cerr << "The Battle cannot take place as there are invalid stats" << std::endl;
            return false;
        }
        return true;
    }
};

#endif