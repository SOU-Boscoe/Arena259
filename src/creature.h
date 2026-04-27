#ifndef CREATURE_H
#define CREATURE_H

#include <string>
#include <iostream>

const int MIN_HEALTH = 80;
const int MAX_HEALTH = 120;

class Creature
{
private:
    std::string name;
    int health;
    int damage;
    std::string type;  // Enhancement: Added type/tag for creature categorization (e.g., "Humanoid", "Beast"). This allows better organization and future features like type-based abilities.
    static int creatureCount;  // Static member: Tracks total creatures created across all instances. Private to prevent external modification.

public:
    // Constructor: Now uses initializer list for efficient member initialization (avoids default construction then assignment).
    Creature(std::string n, int h, int d, std::string t)
        : name(n), health(h), damage(d), type(t) {
        creatureCount++;  // Increment static count on creation.
    }

    // Accessor methods: Const to ensure no modification; provides read-only access for encapsulation.
    std::string getName() const { return name; }
    int getHealth() const { return health; }
    int getDamage() const { return damage; }
    std::string getType() const { return type; }  // New: Accessor for type.

    // Behavior methods
    void attack(Creature &other) {
        other.takeDamage(damage);  // Updated: Uses takeDamage for modularity instead of direct health access.
    }

    void takeDamage(int dmg) {  // New method: Encapsulates damage logic, allowing for future enhancements like damage mitigation or special effects.
        health -= dmg;
        if (health < 0) {
            health = 0;
        }
    }

    bool isAlive() const {  // Made const: Ensures method doesn't modify state.
        return health > 0;
    }

    // Static methods
    static int getCreatureCount() { return creatureCount; }  // Returns total creatures created.

    static bool validate(const Creature &c) {  // Updated: Uses accessors since data is now private; made param const for safety.
        if (c.getHealth() < MIN_HEALTH || c.getHealth() > MAX_HEALTH) {
            std::cerr << "Error: " << c.getName() << " has invalid health. Health must be between " << MIN_HEALTH << " and " << MAX_HEALTH << std::endl;
            return false;
        }
        if (c.getDamage() <= 0 || c.getDamage() > 20) {
            std::cerr << "Error: " << c.getName() << " has invalid damage. Damage must be > 0 or <= 20" << std::endl;
            return false;
        }
        return true;
    }

    static bool validateBattle(const Creature &a, const Creature &b) {  // Updated: Params const; uses validate with accessors.
        if (!validate(a) || !validate(b)) {
            std::cerr << "The Battle cannot take place as there are invalid stats" << std::endl;
            return false;
        }
        return true;
    }
};

// Static member initialization: Must be outside class definition.
int Creature::creatureCount = 0;

#endif