#include "Player.h"

Player::Player(double X ,double Y , const char* name , int id , int hp )
  :Entity(X,Y), Identity(id), hp(hp){
    //std::cout << "Player constructor" << std::endl;
    this->name = nullptr;

    if(name == nullptr){
      this->name = nullptr;
      return;
    }

    size_t nameSz = strlen(name);
    this->name = new char[nameSz + 1];
    strcpy(this->name, name);
  }

  Player::~Player(){
    delete[] name;
    //std::cout << "Player destr" << std::endl;
  }

  Player::Player(const Player& other)
  :Entity(other.X, other.Y), 
  Identity(other.getId()){
    this-> hp = other.hp;
    size_t sz = strlen(other.name);
    this->name = new char[sz+1];
    strcpy(this->name,other.name);
  }

  Player& Player::operator=(const Player& other){
    if(this != &other){
      setCoordinates(other.X,other.Y);
      this->hp = other.hp;
      this->setID(other.getId());

      delete[] name;
      size_t sz = strlen(other.name);
      this->name = new char[sz+1];
      strcpy(this->name,other.name);
    }
    return *this;
  }

  void Player::printName() const{
    std::cout << "Entity name: " << name << std::endl;
  }