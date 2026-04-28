#ifndef CREATURE_H
#define CREATURE_H

#include <iostream>


const int MIN_HEALTH = 80;
const int MAX_HEALTH = 120;
static int creatureCount = 0;


class Creature{
private:
    std::string name;
    int health;
    int damage;
    int speed;

public:
    //instantiates Creature object
    Creature(std::string n, int h, int d);

    //determins how much damage the creature will do
    int attack();

    //takes the damage value from the attack function and subtracts 
    //that from the second creatures health.
    void takeDamage(int d);

    //determins a speed stat for the creature having negative effects
    //if the health or damage stats of the creature is high.
    void determinSpeed();

    //Checks if the creature is alive.
    const bool isAlive(Creature &current);

    //getter and setter functions
    const std::string getName();

    const int getHealth();

    const int getDamage();

    const int getSpeed();

    void setName(string::n);

    void setHealth(int h);
    
    void setDamage(int d);

    void setSpeed(int s);
};

#endif
//this code is leftover functions from when I modified the class in Lab2.
    /*
    const bool validate(Creature &current){
        if(current.health < MIN_HEALTH || current.health > MAX_HEALTH){
            std::cerr << "Error: " << current.name << " has invalid health. Health must be between " << MIN_HEALTH << " and " << MAX_HEALTH << std::endl;
            return false;
        }
        if(current.damage <= 0 || current.damage > 20){
            std::cerr << "Error: " << current.name << " has invalid damage. Damage must be > 0 or <= 20" << std::endl;
            return false;
        }
        return true;
        // minimum health to start a battle is 80, otherwise the battle would be predictable
        // 
    }
    */

    /*
    If Creature a or b does not have the valid stats for health or damage
    It will output an error message and abort
    */

    /*
    const bool validateBattle(Creature &a, Creature &b){
        if(!validate(a) || !validate(b)){
            std::cerr << "The Battle cannot take place as there are invalid stats" << std::endl;
            return false;
        }
        return true;
    }
    */