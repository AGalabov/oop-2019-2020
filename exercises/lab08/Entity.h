#pragma once
#include <iostream>

class Entity
{

public:
    static const int type;

protected:
    double X, Y;
    long long id;
    int hp;

public:
    Entity(double = 0.0, double = 0.0, long long = 1);
    virtual ~Entity();

    int getHp();
    long long getId();
    virtual void printVal() = 0;

    virtual void attack(Entity &) = 0;
    void takeDamage(int);

    virtual void print(std::ostream &) = 0;
};