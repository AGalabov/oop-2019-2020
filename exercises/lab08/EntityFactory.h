#pragma once
#include "Warrior.h"
#include "Mage.h"

class EntityFactory
{
public:
    static Entity *readEntity(std::istream &);
    static Entity* readEntityBin(std::istream&);
};