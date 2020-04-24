#pragma once
#include "Entity.h"

class Warrior : public Entity
{
    unsigned int endurance;
    int attackStrength;
    double kg;

public:
    static const int type = 1;
    Warrior(double, double, long long, unsigned int = 100, int = 30, double = 69.92);
    ~Warrior();

    unsigned int getEndurance();

    void printVal();
    void attack(Entity &);

    void print(std::ostream &out);
    static Warrior *read(std::istream &);
};