#include "Warrior.h"

const int Warrior::type;

Warrior::Warrior(double X, double Y, long long id, unsigned int endurance, int attStrengh, double kg)
    : Entity(X, Y, id), endurance(endurance), attackStrength(attStrengh), kg(kg)
{
}

Warrior::~Warrior()
{
    //std::cout << "Warrior destructor for " << this->id << std::endl;
}

unsigned int Warrior::getEndurance()
{
    return this->endurance;
}

void Warrior::attack(Entity &other)
{
    std::cout << "Warrior attack" << std::endl;
    other.takeDamage(attackStrength);
    this->endurance -= 7;
}

void Warrior::printVal()
{
    std::cout << "Warrior endurance: " << this->endurance << std::endl;
}

void Warrior::print(std::ostream &out)
{
    out << Warrior::type << " ";
    Entity::print(out);
    out << this->endurance << " " << this->attackStrength << " " << this->kg << std::endl;
}

Warrior *Warrior::read(std::istream &in)
{
    int X, Y, attackStrength, hp;
    long long id;
    unsigned int endurance;
    double kg;

    in >> id >> X >> Y >> hp >> endurance >> attackStrength >> kg;
    // Note we are ignored hp - we are creating them with full health

    return new Warrior(X, Y, id, endurance, attackStrength, kg);
}

int Warrior::getType(){
    return Warrior::type;
}

void Warrior::writeToBinFile(std::ofstream& out){
    out.write((char*)&(this->type),sizeof(int));
    out.write((char*)this,sizeof(Warrior));
}