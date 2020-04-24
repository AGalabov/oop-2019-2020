#include "Entity.h"

Entity::Entity(double X, double Y, long long id)
{
    this->X = X;
    this->Y = Y;
    this->id = id;
    this->hp = 100;
}

Entity::~Entity()
{
    std::cout << "Entity destructor for" << this->id << std::endl;
}

long long Entity::getId()
{
    return this->id;
}

int Entity::getHp()
{
    return this->hp > 0 ? this->hp : 0;
}

void Entity::takeDamage(int dmg)
{
    this->hp -= dmg;
}

void Entity::print(std::ostream &out)
{
    out << this->id << " "
        << this->X << " "
        << this->Y << " "
        << this->hp << " ";
}
