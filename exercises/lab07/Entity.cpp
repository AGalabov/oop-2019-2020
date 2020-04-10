#include "Entity.h"

Entity::Entity(double X , double Y ){
    this-> X = X;
    this-> Y = Y;
    //std::cout << "Entity constructor" << std::endl;
  }

  Entity::~Entity(){
    //std::cout << "Entity destr" << std::endl;
  }

  void Entity::setCoordinates(double x,double y){
    this-> X = x;
    this-> Y = y;
  }

  void Entity::move(double dx,double dy){
    this-> X += dx;
    this-> Y += dy;
  }

  void Entity::printCoordinates(){
    std::cout << "X: " << X << " Y: " << Y << std::endl;
  }