#include "Creature.h"
#include <string>
#include <iostream>

    //instantiates Creature object
    Creature::Creature(std::string n, int h, int d) : name(n), health(h), damage(d){}

    //determins how much damage the creature will do
    Creature::attack(){
        return damage;
    }

    //takes the damage value from the attack function and subtracts 
    //that from the second creatures health.
    Creature::takeDamage(int d){
        health -= damage;
    }

    //determins a speed stat for the creature having negative effects
    //if the health or damage stats of the creature is high.
    Creature::determinSpeed(){
        if(health > 115 || damage > 40){
            speed = 1;
        }

        else if(health > 110 || damage > 30){
            speed = 2;
        }

        else if(health > 100 || damage > 20){
            speed = 3;
        }

        else{
            speed = 4;
        }
    }

    //Checks if the creature is alive.
    Creature::isAlive(Creature &current){
        return health > 0;
    }

    //getter and setter functions
    Creature::getName(){
        return name;
    }

    Creature::getHealth(){
        return health;
    }

    Creature::getDamage(){
        return damage;
    }

    Creature::getSpeed(){
        return speed
    }
    
    Creature::setName(std::string n){
        name = n;
    }

    Creature::setHealth(int h){
        health = h;
    }

    Creature::setDamage(int d){
        damage = d;
    }

    Creature::setSpeed(int s){
        speed = s;
    }