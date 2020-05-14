
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

Entity* EntityFactory::readEntityBin(std::istream& in){
        int currType = -1;
        in.read((char*)&currType, sizeof(currType));

        if(currType == Mage::type){
            Mage* toRet = new Mage(0,0,0,0,0);
            in.read((char*)toRet,sizeof(Mage));
            return toRet;
        }
        else if(currType == Warrior::type){
            Warrior* toRet = new Warrior(0,0,0,0,0,0);
            in.read((char*)toRet,sizeof(Warrior));
            return toRet;
        }
        else{
            std::cout << "Bad entity type" << std::endl;
        }
}