#include "dragon.h"

Dragon dragon;
Creature goblin("Goblin", 50, 8);

dragon.attack(goblin);
dragon.specialMove(goblin);

// which function is inherited? Attack function
// which function is overridden? SpecialMove function
// what happens during attack()? The dragon performs a normal attack on the goblin, dealing damage based on its attack power
// what happens during specialMove()? The dragon uses its special move, Fire Breath, 25 damage
