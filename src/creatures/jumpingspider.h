#ifndef jUMPINGSPIDER_H
#define Jumpingspider_H
#include "../creature.h"

class Jumpingspider : public Creature {
        public:
                Jumpingspider();
                void specialMove(Creature& other) override;
};

#endif

