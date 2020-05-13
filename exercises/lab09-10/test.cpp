#include <iostream>
#include "PrivateCompany.h"
#include "StateCompany.h"
#include "Consortium.h"
#include <fstream>

int main(){
  PrivateCompany p1("Bulgarian B",2);
  StateCompany s1 ("VV", 20);
  Consortium c1("GG");
  c1.add(&p1);
  PrivateCompany p2("DD",4);

  std::ifstream projects("projects.txt");
  if(!projects.is_open()){
    std::cout << "Couldn't open projects.txt " <<std::endl;
    return 0;
  }

  std::string project;
  while(!projects.eof()){
    std::getline(projects,project);
    c1.perform(project);
  }

  projects.close();

  std::cout << c1;
  return 0;
}