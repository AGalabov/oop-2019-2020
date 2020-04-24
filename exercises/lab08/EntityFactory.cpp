
#include "EntityFactory.h"

Entity *EntityFactory::readEntity(std::istream &in)
{
    int type;
    // 0 = mage
    // 1 = warrior
    in >> type;
    if (type == Mage::type)
    {
        return Mage::read(in);
    }
    if (type == Warrior::type)
    {
        return Warrior::read(in);
    }
}