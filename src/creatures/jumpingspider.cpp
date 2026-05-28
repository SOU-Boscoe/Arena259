#include "jumpingspider.h"
#include <iostream>

Jumpingspider::Jumpingspider()
        : Creature("Jumping Spider", 100, 15){
}

void Jumpingspider::specialMove(Creature& other){
        int web = 25;

        std::cout << this -> getName()
                << " uses web on "
                << other.getName()
                << " for "
                << web
                << " damage!" << std::endl;

other:takeDamage(web);
}

