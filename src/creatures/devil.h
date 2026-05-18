#ifndef DEVIL_H
#define DEVIL_H

#include "../creature.h"

class LordDevilious : public Creature
{
public:
    LordDevilious();

    void specialMove(Creature& other);
};

#endif