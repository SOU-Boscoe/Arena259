#include "creature.h"

int Creature::creatureCount = 0;

/*Implimentation of the Full data feild constructor*/
Creature::Creature(std::string n, int h, int d): name(n), health(h), damage(d){
    creatureCount++;
}

/*Default destructor, decriments creatureCount*/
Creature::~Creature(){
    creatureCount--;
}

/*Attack method, uses the "takeDamage" method of the other creature to inflict damage onto an opponent"*/
void Creature::attack(Creature &other) const{
        other.takeDamage(damage);
}

/*Implimentation of takeDamage, used for inflicting damage on creature itself. Used by the "attack" method, keeps the private data field modifiers acting within the scope of the creature they belong to*/
void Creature::takeDamage(int d){
    if (!isAlive() || d > MAX_DAMAGE || d < MIN_DAMAGE) return; //check if creature is alive before damaging, and checks damage value for out of range
    health -= d;
    if (health < 0){
        health = 0; //ensures non neg health vals
    }
}

/*Implimentation of isAlive, Returns true if the creatures health is > 0, and false if it is <= 0*/
bool Creature::isAlive() const{
    return health > 0;
}

/*Implimentation of validate, ensures that a creature has in bound health and damage vals*/
bool Creature::validate(Creature &c){
    if(c.getHealth() < MIN_HEALTH || c.getHealth() > MAX_HEALTH){
         std::cerr << "Error: " << c.name << " has invalid health. Health must be between " << MIN_HEALTH << " and " << MAX_HEALTH << std::endl;
         return false;
     }
     if(c.getDamage() <= MIN_DAMAGE || c.getDamage() > MAX_DAMAGE){
         std::cerr << "Error: " << c.name << " has invalid damage. Damage must be > 0 and <= 20" << std::endl;
         return false;
      }
      return true;
      // minimum health to start a battle is 80, otherwise the battle would be predictable 
}

/*Implimentation of validateBattle, ensures that two creatures have in bound health and damage values before a battle takes place (I think this should go in arena.cpp -Sebastian)*/
bool Creature::validateBattle(Creature &a, Creature &b){
        if(!validate(a) || !validate(b)){
            std::cerr << "The Battle cannot take place as there are invalid stats" << std::endl;
            return false;
        }
        return true;
}

/*Implimentation of getCreatureCount, for getting private static data member (creatureCount)*/
int Creature::getCreatureCount(){
    return creatureCount;
}

/*Implimentation of getName, for getting private data member (name)*/
std::string Creature::getName() const{
    return name;
}

/*Implimentation of getHealth, for getting private data member (health)*/
int Creature::getHealth() const{
    return health;
}

/*Implimentation of getDamage, for getting private data member (damage)*/
int Creature::getDamage() const{
    return damage;
}

/*Implimentation of setHealth, for setting private data member (health)*/
void Creature::setHealth(int newHealth){
    if (newHealth <= MAX_HEALTH){
        health = newHealth;
    }
}

/*Implimentation of setDamage, for setting private data member (damage)*/
void Creature::setDamage(int newDamage){
    if (newDamage <= MAX_DAMAGE){
        damage = newDamage;
    }
}