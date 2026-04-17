#include "viper.h"

Creature makeViper()
{
    std::string n = "Viper";
    int h = 90;
    int d = 20;
    return Creature(n, h, d);
}