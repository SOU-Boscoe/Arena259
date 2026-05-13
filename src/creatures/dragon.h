#ifndef DRAGON_H
#define DRAGON_H
#include "creature.h"

class Dragon : public Creature {
    public:
    Dragon();

    void specialMove(Creature& other) override;
};


#endif


// What is the base class? Creature
// What is the derived class? Dragon
// What does this line mean? class Dragon : public Creature // it means that Dragon is a derived class of Creature, and it inherits all the public and protected members of Creature, and it can also override virtual functions of Creature to provide its own implementation. The "public" keyword means that the public members of Creature will remain public in Dragon, and the protected members of Creature will remain protected in Dragon.
// What functions does Dragon inherit from Creature? getName(), getHealth(), getDamage(), attack(), takeDamage(), and any other non-virtual functions defined in Creature
// What function does Dragon customize? specialMove()
// What does override mean? it means that this function is meant to override a virtual function in the base class, and it allows the compiler to check that we are actually overriding a function that exists in the base class, and it also makes the code more readable by indicating that this function is an override of a base class function
