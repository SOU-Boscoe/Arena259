#ifndef CREATURE_H
#define CREATURE_H

#include <string>
#include <iostream>

const int MIN_HEALTH = 80;
const int MAX_HEALTH = 120;
const int MIN_DAMAGE = 0;
const int MAX_DAMAGE = 20;


class Creature
{
private:

    std::string name;
    int health;
    int damage;

    static int creatureCount;

public:

    /*Full data feild constructor, passes in a string for "name", int for "health", and int for "damage"*/
    Creature(std::string n, int h, int d);

    /*Default destructor*/
    ~Creature();

    /*Attack method used to inflict damage onto an opponent", passes in a creature reference as the opponent*/
    void attack(Creature &other) const;

    /*Self damage method, passes in an int for the damage dealt*/
    void takeDamage(int d);

    /*Checker that returns true if the creature is alive and false if the creature is dead*/
    bool isAlive() const;
    
    /*Checker that returns true if the creature is valid and false if the creature is non-valid, passes in a creature reference*/
    static bool validate(Creature &c);

    /*Checker that returns true if either of the two creatures are valid and false if the creatures are non-valid, passes in two creature references*/
    static bool validateBattle(Creature &a, Creature &b);

    static int getCreatureCount();

    /*Getter for private data member (name)*/
    std::string getName() const;

    /*Getter for private data member (health)*/
    int getHealth() const;

    /*Getter for private data member (damage)*/
    int getDamage() const;

    /*Setter for private data member (health), passes in int for the new health value*/
    void setHealth(int newHealth);

    /*Setter for private data member (damage), passes in int for the new damage value*/
    void setDamage(int newDamage);

};


#endif