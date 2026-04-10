#ifndef CREATURE_H
#define CREATURE_H

#include <iostream>
#include <string>

class Creature
{
protected:
    std::string name;
    int health;

public:
    Creature(std::string n, int h) : name(n), health(h) {}

    virtual void attack(Creature &other) = 0;

    void takeDamage(int amount)
    {
        health -= amount;
        if (health < 0)
            health = 0;
    }

    bool isAlive() const
    {
        return health > 0;
    }

    std::string getName() const
    {
        return name;
    }

    int getHealth() const
    {
        return health;
    }

    virtual ~Creature() = default;
};

class Imp : public Creature {
    public: 
        Imp() : Creature("Imp", 60){};

        ~Imp() = default; 

        void attack(Creature &other) override {
            int damage = attack_ - ((rand() % 10) - 1);
            std::cout << "Imp claws at " << other.getName() << " furiously!" << std::endl;
            std::cout << other.getName() << " takes " << damage << " damage!" << std::endl;
            other.takeDamage(damage);}

        void special(Creature &other) {}

    private:
        int attack_= 16;
};

class Cherub : public Creature {
    public: 
        Cherub() : Creature("Cherub", 60){};

        ~Cherub() = default; 

        void attack(Creature &other) override {
            int damage = attack_ + ((rand() % 8) + 1);
            std::cout << "Cherub sings at " << other.getName() << " lovingly!" << std::endl;
            std::cout << other.getName() << " takes " << damage << " damage!" << std::endl;
            other.takeDamage(damage);}

        void special(Creature &other) {}

    private:
        int attack_= 10;
};

#endif