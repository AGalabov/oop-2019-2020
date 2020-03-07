#include <iostream>

class Point
{
private:
    double x;
    double y;

public:
    Point();
    Point(double, double);
    double getX();
    double getY();
    void setX(double);
    void setY(double);
    void print();
};

Point::Point()
{
    this->x = 0;
    this->y = 0;
}

Point::Point(double x, double y)
{
    this->x = x;
    this->y = y;
}

double Point::getX()
{
    return this->x;
}

double Point::getY()
{
    return this->y;
}

void Point::setX(double x)
{
    this->x = x;
}

void Point::setY(double y)
{
    this->y = y;
}

void Point::print()
{
    std::cout << "(" << this->x << ", " << this->y << ")\n";
}

int main()
{
    Point p1;           // this is the same as Point p1() -> creates a Point (0,0)
    Point p2(3.14, 42); // creates a Point with coordinates x=3.14 and y=42

    // we get access to x and y coordinates through geters
    std::cout << p1.getX() << " " << p1.getY() << std::endl;
    // p1.x and p1.y result in errors (they are inaccessible)

    p1.print();
    p2.print();

    p1.setX(5.67); // modify x coordinate
    p1.setY(3.14); // modify y coordinate
    p1.print();    // prints p1 with its modified coordinates: (5.67, 3.14)

    return 0;
}