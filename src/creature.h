// An incomplete example of what a base creature class might look like.

class Creature
{
protected:
    std::string name;
    int health;

public:
    Creature(std::string n, int h) : name(n), health(h) {}

    virtual void attack(Creature &other) = 0;

    void takeDamage(int amount)
    {
        health -= amount;
        if (health < 0)
            health = 0;
    }

    bool isAlive() const
    {
        return health > 0;
    }

    std::string getName() const
    {
        return name;
    }

    int getHealth() const
    {
        return health;
    }

    virtual ~Creature() = default;
};
