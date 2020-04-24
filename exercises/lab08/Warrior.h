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

    unsigned int getEndurance();

    void getVal();

    void printPretty(std::ostream &out);
    void printBinary(std::ostream &);
    static Warrior *read(std::istream &);
    static Warrior *readBinary(std::istream &);

    void attack(Entity &);
    ~Warrior();
};