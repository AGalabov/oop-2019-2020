#pragma once
#include"Player.h"

class Mage : public Player{
  unsigned int mana;
  int spellStrength;
  
  public:
  using Player::operator=;
  Mage(double , double , const char* , int id, unsigned int  = 100,
   unsigned int = 85, int = 50);

   void setMana(unsigned int );
   unsigned int getMana();

   void attack(Mage&);
};