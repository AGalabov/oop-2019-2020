#include <iostream>

class A
{
protected:
    int a;

public:
    A() : a(0)
    {
        std::cout << "Default Constructor A: " << a << std::endl;
    }
    A(int _a) : a(_a)
    {
        std::cout << "Constructor A: " << a << std::endl;
    }
    virtual void print()
    {
        std::cout << "A: " << a << std::endl;
    }
    virtual ~A() = default;
};

class B : public virtual A
{
protected:
    int b;

public:
    B() : b(0) {}
    B(int _a) : A(_a)
    {
        std::cout << "Constructor B: " << a << std::endl;
    }

    void print()
    {
        std::cout << "B: " << a << std::endl;
    }
};

class C : public virtual A
{
protected:
    int c;

public:
    C() : c(1) {}
    C(int _a) : A(_a)
    {
        std::cout << "Constructor C: " << a << std::endl;
    }

    void print()
    {
        std::cout << "C: " << a << std::endl;
    }
};

class D : public B, public C
{
public:
    D(int _a) : A(_a)
    {
        std::cout << "Constructor D: " << a << std::endl;
    }

    void print()
    {
        std::cout << "D: " << a << " " << b << " " << c << std::endl;
    }
};

int main()
{
    A *ptr = new D(3);
    ptr->print();

    delete ptr;
    return 0;
}