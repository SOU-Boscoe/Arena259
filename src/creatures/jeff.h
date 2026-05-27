#ifndef JEFF_H
#define JEFF_H

#include <string>
#include <iostream>
#include "creature.h"

class Jeff : public Creature {
public:
	// Constructor 
	Jeff(std::string name, int health, int damage);

	void specialMove(Creature& other) override;
};

#endif