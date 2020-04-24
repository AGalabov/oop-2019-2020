#include "Warrior.h"

Warrior::Warrior(double X, double Y, long long id, unsigned int endurance, int attStrengh, double kg)
    : Entity(X, Y, id), endurance(endurance), attackStrength(attStrengh), kg(kg)
{
}

const int Warrior::type;

unsigned int Warrior::getEndurance()
{
    return this->endurance;
}

void Warrior::attack(Entity &other)
{
    std::cout << "Warrior attack";
    other.takeDamage(attackStrength);
    this->endurance -= 7;
}

void Warrior::getVal()
{
    std::cout << "Warrior endurance: " << this->endurance << std::endl;
}

Warrior::~Warrior()
{
    std::cout << "Warrior destructor for" << this->id << std::endl;
}

void Warrior::printPretty(std::ostream &out)
{
    out << Warrior::type << " ";
    Entity::printPretty(out);
    out << this->endurance << " " << this->attackStrength << " " << this->kg << std::endl;
}

Warrior *Warrior::read(std::istream &in)
{
    int X, Y, attackStrength, hp;
    long long id;
    unsigned int endurance;
    double kg;

    in >> id >> X >> Y >> hp >> endurance >> attackStrength >> kg;

    return new Warrior(X, Y, id, endurance, attackStrength, kg);
}
