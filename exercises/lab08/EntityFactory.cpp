
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

Entity *EntityFactory::readEntityBinary(std::istream &in)
{
    int type;
    in.read((char *)(&type), sizeof(type));
    if (type == Mage::type)
    {
        return Mage::readBinary(in);
    }
    if (type == Warrior::type)
    {
        return Warrior::readBinary(in);
    }
}