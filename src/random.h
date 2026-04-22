#ifndef RANDOM_H
#define RANDOM_H

#include <random>


class Random {
    public:
        inline static bool flipCoin() { return COIN(yield);};
        inline static int randomValue(int min, int max) { return std::uniform_int_distribution<>{min, max}(yield); }
    private:
        inline static std::random_device rd{};
        inline static std::mt19937 yield{rd()};
        inline static std::uniform_int_distribution<> COIN{0,1};
};

#endif