#ifndef CREATURE_H
#define CREATURE_H

#include <string>
#include <iostream>

class Creature
{

private:
    std::string name;
    int health;
    int damage;
    int defense;        // Added defense stat

    // Added the count of creatures but still includes copies
    inline static int creatureCount = 0;

public:

    // Changed to use Initialiser
    Creature(std::string n, int h, int d, int def = 0)
    : name(n), health(h), damage(d), defense(def){
        creatureCount++;
    }

    // Adding the accessirs, the getters
    std::string getName() const{
        return name;
    }

    int getHealth() const{
        return health;
    }

    int getDamage() const{
        return damage;
    }

    int getDefense() const{
        return defense;
    }

    static int getCreatureCount(){
        return creatureCount;
    }



    void attack(Creature &other)
    {

        other.health -= damage;
        if (other.health < 0)
        {
            other.health = 0;
        }
    }

    bool isAlive()
    {
        return health > 0;
    }

    static bool validate(Creature &c){
        if(c.health <= 0 || c.health > 120){
            std::cerr << "Error: " << c.name << " has invalid health. Health must be > 0 or <= 120" << std::endl;
            return false;
        }
        if(c.damage <= 0 || c.damage > 20){
            std::cerr << "Error: " << c.name << " has invalid damage. Damage must be > 0 or <= 20" << std::endl;
            return false;
        }
        return true;
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
};

#endif