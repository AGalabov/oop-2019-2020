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

    void setCoordinates(double, double);

    void move(double, double);

    void takeDamage(int);

    int getHp();

    long long getId();

    virtual void attack(Entity &) = 0;

    virtual void getVal() = 0;

    void printCoordinates();

    virtual ~Entity();

    virtual void printPretty(std::ostream &) = 0;
};