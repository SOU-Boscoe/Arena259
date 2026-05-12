#ifndef DRAGON_H
#define DRAGON_H
#include "creature.h"

class Dragon : public Creature {
    public:
    Dragon();

    void specialMove(Creature& other) override;
};
// what is the base class? Creature
// what is the derived class? Dragon
// what does public Creature mean? it means that Dragon inherits from Creature, and that the public and protected members of Creature are also public and protected members of Dragon
// what does override mean? it means that this function is meant to override a virtual function in the base class Creature

#endif