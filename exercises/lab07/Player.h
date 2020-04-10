#pragma once
#include "Entity.h"
#include "Identity.h"

class Player : public Entity, public Identity{
  protected:
  char* name;
  unsigned int hp;

  public:
  Player(double = 0.0 , double = 0.0, const char* = nullptr, int = 0, int = 100);
  ~Player();

  Player(const Player&);
  Player& operator=(const Player&);

   void printName() const;
};