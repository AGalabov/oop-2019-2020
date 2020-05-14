#pragma once
#include <iostream>
#include <cstring>

class Identity
{
  int id;

public:
  Identity(int);
  ~Identity();

  int getId() const;
  void setID(int ID);
};