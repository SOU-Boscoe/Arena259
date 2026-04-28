#include <string>
#include <iostream>

    Creature::Creature(std::string n, int h, int d) : name(n), health(h), damage(d){}

    Creature::attack()
    {

        other.health -= current.damage;
        if (other.health < 0)
        {
            other.health = 0;
        }
    }

    Creature::isAlive()
    {
        return current.health > 0;
    }
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

    Creature::getName(){
        return name;
    }

    Creature::getHealth(){
        return health;
    }

    Creature::getDamage(){
        return damage;
    }