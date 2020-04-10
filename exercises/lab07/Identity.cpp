#include "Identity.h"

Identity::Identity(int id):id(id){
    //std::cout << "Ident constr" << std::endl;
  }

  Identity::~Identity(){
    //std::cout << "Ident destr" << std::endl;
  }

  int Identity::getId() const{
    return id;
  }

  void Identity::setID(int ID){
    this->id = ID;
  }