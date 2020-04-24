#include "EntityFactory.h"

#include <fstream>

void harm(Entity* subject, double dmg) 
{
   subject->takeDamage(dmg);
}

int main(){

  std::ifstream in("Entities.bin", std::ios::in | std::ios::binary);

  int n = 3;
  // in >> n;

  Entity** entities = new Entity*[n];

  for(int i = 0; i< n; i++)
  {
    entities[i] = EntityFactory::readEntityBinary(in);
  }

  in.close();

  // for(int i = 0; i< n; i++)
  // {
  //     entities[i]->attack(*entities[(i+1)%n]);
  // }

  // std::ofstream out("Entities.bin", std::ios::out | std::ios::binary);

  for(int i = 0; i< n; i++)
  {
      entities[i]->printBinary(std::cout);
  }

  for(int i = 0; i< n; i++)
  {
    delete entities[i];
  }

  // out.close();

  delete [] entities;


  return 0;
}