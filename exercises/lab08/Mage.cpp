#include "Mage.h"

const int Mage::type;

Mage::Mage(double X, double Y, long long id, unsigned int mana, int spellStr)
    : Entity(X, Y, id), mana(mana), spellStrength(spellStr)
{
}

Mage::~Mage()
{
    //std::cout << "Mage destructor for " << this->id << std::endl;
}

unsigned int Mage::getMana()
{
    return this->mana;
}

void Mage::setMana(unsigned int mana)
{
    this->mana = mana;
}

void Mage::attack(Entity &other)
{
    std::cout << "Mage attack" << std::endl;
    other.takeDamage(spellStrength);
    this->setMana(this->getMana() - 10);
}

void Mage::printVal()
{
    std::cout << "Mage mana: " << this->mana << std::endl;
}

void Mage::print(std::ostream &out)
{
    out << Mage::type << " ";
    Entity::print(out);
    out << this->mana << " " << this->spellStrength << std::endl;
}

Mage *Mage::read(std::istream &in)
{
    int X, Y, spellStrength, hp;
    long long id;
    unsigned int mana;

    in >> id >> X >> Y >> hp >> mana >> spellStrength;
    // Note we are ignored hp - we are creating them with full health

    return new Mage(X, Y, id, mana, spellStrength);
}

int Mage::getType(){
    return Mage::type;
}

void Mage::writeToBinFile(std::ofstream& out){
    out.write((char*)&(this->type),sizeof(int));
    out.write((char*)this,sizeof(Mage));
}