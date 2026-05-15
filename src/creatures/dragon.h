#ifndef DRAGON_H
#define DRAGON_H

#include "../creature.h"

class Dragon:public Creature {
	public:
		Dragon();

		void specialMove(Creature& other) override;
};

#endif
