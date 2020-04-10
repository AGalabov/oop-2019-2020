#include "Mage.h"

int main(){
  
  std::cout <<"Entity size: " <<sizeof(Entity) << std::endl;
  std::cout <<"Player size: " <<sizeof(Player) << std::endl;
  std::cout <<"Mage size: " << sizeof(Mage) << std::endl;


  //Entity ent(2,5);
  Mage player(3, 6, "Pesho", 1, 60);
  Mage player2(4, 8,"Tosho", 2);
  Mage pl3(6, 7, "Ivan", 3, 200, 30);
  // std::cout << player2.getId() << " Mana: " << player2.getMana() << std::endl;
  // player2.printName();
  // player2 = player;
  // player2.printName();
  // std::cout << player2.getId() << " Mana: " << player2.getMana()<<std::endl;
  // player2.printCoordinates();

  player.attack(player2);
  player.attack(pl3);

/*
  player.printName();
  ent.printCoordinates();
  player.printCoordinates();
  player.move(2.5, -0.3);
  player.printCoordinates();
*/

  //std::cout << player.getId() << std::endl;


  return 0;
}