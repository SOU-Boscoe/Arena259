#ifndef JEFF_H
#define JEFF_H

#include <string>
#include <iostream>
#include "../creature.h"

class Jeff : public Creature {
public:
	// Constructor 
	Jeff();
	~Jeff() override;

	void specialMove(Creature& other) override;
};

#endif