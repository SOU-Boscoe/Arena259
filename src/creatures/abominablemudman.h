#ifndef DRAGON_H
#define DRAGON_H

#include "../creature.h"

class AbominableMudman : public Creature {
    private:

    public:
        AbominableMudman();

        void specialMove(Creature& other) override;

};
#endif