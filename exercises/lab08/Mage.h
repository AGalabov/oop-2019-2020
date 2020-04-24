#pragma once
#include "Entity.h"

class Mage : public Entity
{
    unsigned int mana;
    int spellStrength;

public:
    static const int type = 0;
    Mage(double, double, long long, unsigned int = 85, int = 50);
    ~Mage();

    unsigned int getMana();
    void setMana(unsigned int);

    void getVal();
    void attack(Entity &);

    void print(std::ostream &);
    static Mage *read(std::istream &);
};