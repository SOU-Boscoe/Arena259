#ifndef DEVIL_H
#define DEVIL_H


#include "../creature.h" // include the base class header

class LordDevilious : public Creature 
{
public:
    LordDevilious();
    ~LordDevilious() = default;

    void specialMove(Creature& other); // override the base class special move with a unique one for this creature
};

#endif