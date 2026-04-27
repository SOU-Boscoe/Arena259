#ifndef CREATURE_H
#define CREATURE_H

#include <string>
#include <iostream>

const int MIN_HEALTH = 80;
const int MAX_HEALTH = 120;


class Creature
{
public:
    //Getters method for name, health, and for my idea/suggestion: Defense!
    std::string getName() const { return name; }
    int getHealth() const { return health; }
    int getDamage() const { return damage; }
    int getDefense() const { return defense; }

    // Reformed constructor to work with the new getter dethods instead.
    Creature(std::string n, int h, int d, int def): name(n), health(h), damage(d), defense(def) {}

    creatureCount++;

   void takeDamage(int dmg)
    {
        health -= std::max(0, dmg - defense); // Implementing defense into takeDamage method to make it work. Simple implmentation, defense subtracts damage.
    }
    void attack(Creature &target)
    {
        target.takeDamage(damage);
    }


    bool isAlive() const
    {
        return health > 0;
    }

    static int creatureCount;

    static int getCreatureCount() {
        return creatureCount;
    }

    static bool validate(Creature &c){
        if(c.health < MIN_HEALTH || c.health > MAX_HEALTH){
            std::cerr << "Error: " << c.name << " has invalid health. Health must be between " << MIN_HEALTH << " and " << MAX_HEALTH << std::endl;
            return false;
        }
        if(c.damage <= 0 || c.damage > 20){
            std::cerr << "Error: " << c.name << " has invalid damage. Damage must be > 0 or <= 20" << std::endl;
            return false;
        }
        return true;
        // minimum health to start a battle is 80, otherwise the battle would be predictable
        // 
    }

    /*
    If Creature a or b does not have the valid stats for health or damage
    It will output an error message and abort
    */
    static bool validateBattle(Creature &a, Creature &b){
        if(!validate(a) || !validate(b)){
            std::cerr << "The Battle cannot take place as there are invalid stats" << std::endl;
            return false;
        }
        return true;
    }

int Creature::creatureCount = 0;

private:
    std::string name;
    int health;
    int damage;
    int defense;
};

#endif