#include "Mage.h"

Mage::Mage(double X, double Y, long long id, unsigned int mana, int spellStr)
    : Entity(X, Y, id), mana(mana), spellStrength(spellStr)
{
}

const int Mage::type;

void Mage::setMana(unsigned int mana)
{
    this->mana = mana;
}

unsigned int Mage::getMana()
{
    return this->mana;
}

void Mage::attack(Entity &other)
{
    std::cout << "Mage attack" << std::endl;
    other.takeDamage(spellStrength);
    this->setMana(this->getMana() - 10);
}

void Mage::getVal()
{
    std::cout << "Mage mana: " << this->mana << std::endl;
}

Mage::~Mage()
{
    std::cout << "Mage destructor for" << this->id << std::endl;
}

void Mage::printPretty(std::ostream &out)
{
    out << Mage::type << " ";
    Entity::printPretty(out);
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