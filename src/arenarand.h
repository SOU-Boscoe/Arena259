#ifndef ARENARAND_H
#define ARENARAND_H

#include <random>


class ArenaRand {
    public:
        static bool flipCoin();
        static int randomValue(int min, int max);
    private:
        inline static std::random_device rd{};
        inline static std::mt19937 gen{rd()};
        inline static std::uniform_int_distribution<> COIN{0,1};
};

#endif