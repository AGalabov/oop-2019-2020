#pragma once
#include "Entity.h"

class Mage : public Entity
{
    unsigned int mana;
    int spellStrength;

public:
    static const int type = 0;
    Mage(double, double, long long, unsigned int = 85, int = 50);

    void setMana(unsigned int);
    unsigned int getMana();

    void getVal();

    void attack(Entity &);

    void printPretty(std::ostream &);
    void printBinary(std::ostream &);
    static Mage *read(std::istream &);
    static Mage *readBinary(std::istream &);

    ~Mage();
};