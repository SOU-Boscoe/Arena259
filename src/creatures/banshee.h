
#ifndef BANSHEE_H
#define BANSHEE_H
#include "creature.h"

class Banshee : public Creature
{
public:
    Banshee();
    void specialMove(Creature& other) override;
};

#endif

// passes test.cpp with banshee and goblin 