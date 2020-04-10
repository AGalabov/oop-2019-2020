#include"Mage.h"

  Mage::Mage(double X, double Y, const char* name, int id, unsigned int mana ,
  unsigned int hp , int spellStr)
  :Player(X, Y, name, id, hp), mana(mana), spellStrength(spellStr){

  }

  void Mage::setMana(unsigned int mana){
    this -> mana = mana;
  }

  unsigned int Mage::getMana(){
    return this->mana;
  }

  void Mage::attack(Mage& other){
    std::cout << "Dmg: " << spellStrength << std::endl;
    int afterAttack = other.hp - spellStrength;

    if(afterAttack <= 0){
      std::cout << "You defeated: ";
      other.printName();
    }
    else{
      std::cout << "Other left with: " << afterAttack << " hp" << std::endl;
    }

    other.hp = (afterAttack <= 0) ? 0 : afterAttack;
    this->setMana(this->getMana() - 10);
  }

  // Mage::Mage& operator=(const Mage& other){
  //   Player :: operator= ((Player)other);
  //   this -> mana = other.mana;
  // }