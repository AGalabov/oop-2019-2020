#include "Entity.h"

Entity::Entity(double X , double Y, long long id ){
    this-> X = X;
    this-> Y = Y;
    this->id = id;
    this->hp = 100;
  }

  void Entity::setCoordinates(double x,double y){
    this-> X = x;
    this-> Y = y;
  }

  void Entity::takeDamage(int dmg)
  {
    this->hp -= dmg;
  }

  long long Entity::getId()
  {
    return this->id;
  }

  int Entity::getHp()
  {
    return this->hp > 0 ? this->hp : 0;
  }

  void Entity::move(double dx,double dy){
    this-> X += dx;
    this-> Y += dy;
  }

  void Entity::printCoordinates(){
    std::cout << "X: " << X << " Y: " << Y << std::endl;
  }

  Entity::~Entity() {
    std::cout << "Entity destructor for" << this->id << std::endl;
  }

  void Entity::printPretty(std::ostream& out) {
        out << this->id   << " "
            << this->X    << " "
            << this->Y    << " " 
            << this->hp   << " ";
  }

  void Entity::printBinary(std::ostream& out) {
        out.write((char*)this, sizeof(Entity));
  }
