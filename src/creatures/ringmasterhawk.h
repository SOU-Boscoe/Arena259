#ifndef RINGMASTERHAWK_H
#define RINGMASTERHAWK_H

#include "../creature.h"

class RingmasterHawk : public Creature {
public:
    RingmasterHawk();
    void specialMove(Creature& other) override;
};

RingmasterHawk makeRingmasterHawk();

#endif