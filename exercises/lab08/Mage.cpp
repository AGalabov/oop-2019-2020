#include "Mage.h"

const int Mage::type;

Mage::Mage(double X, double Y, long long id, unsigned int mana, int spellStr)
    : Entity(X, Y, id), mana(mana), spellStrength(spellStr)
{
}

Mage::~Mage()
{
    std::cout << "Mage destructor for" << this->id << std::endl;
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

    return new Mage(X, Y, id, mana, spellStrength);
}