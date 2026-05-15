

#include "dragon.h"
#include <iostream>


// default constructor
Dragon::Dragon() : Creature("Dragon", 100, 15) {}


void Dragon::specialMove(Creature &other) {
	int fireDamage = 25;
	
	std::cout << getName() << " uses Fire Breath on " << other.getName() << " for "
	<< fireDamage << " damage!" << std::endl;

	other.takeDamage(fireDamage);
}
