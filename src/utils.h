#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <string>
#include <random>

static std::random_device RANDOM_DEVICE; 
static std::mt19937 yield(RANDOM_DEVICE()); 
static std::uniform_int_distribution<> COIN(0, 1);

bool flipCoin() {
    return COIN(yield);
}

enum class Color {
    RESET = 0,
    RED = 31,
    GREEN = 32,
    YELLOW = 33,
    BLUE = 34,
    MAGENTA = 35,
    CYAN = 36,
    WHITE = 37
};

// Helper to output the ANSI escape sequence
std::ostream& operator<<(std::ostream& os, Color color) {
    return os << "\033[" << static_cast<int>(color) << "m";
}

std::string colorMe(std::string text, Color color) {
    return "\033[" + std::to_string(static_cast<int>(color)) + "m" + text + "\033[0m";
}

Color colorPicker() {
    static const Color colors[] = {
        Color::RED,
        Color::GREEN,
        Color::YELLOW,
        Color::BLUE,
        Color::MAGENTA,
        Color::CYAN,
    };

    static const int count = sizeof(colors) / sizeof(colors[0]);

    std::uniform_int_distribution<> dist(0, count - 1);
    return colors[dist(yield)];
}

#endif