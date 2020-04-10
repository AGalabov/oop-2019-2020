#pragma once
#include<iostream>

class Entity{
  protected:
  double X,Y;

  public:
  Entity(double = 0.0, double = 0.0) ;
  ~Entity();

  void setCoordinates(double, double);

  void move(double, double);

  void printCoordinates();
};