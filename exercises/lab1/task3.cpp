#include <iostream>
#include <cmath>
using namespace std;

struct Point
{
    double x;
    double y;
    double z;
    void read()
    {
        cin >> x >> y >> z;
    }
    double distanceTo(Point other)
    {
        double dx = x - other.x;
        double dy = y - other.y;
        double dz = z - other.z;
        return sqrt(sqrt(dx * dx + dy * dy) + dz * dz);
    }
    double distanceToCenter()
    {
        return sqrt(sqrt(x * x + y * y) + z * z);
    }
    void print()
    {
        cout << "(" << x << ", " << y << ", " << z << ")" << endl;
    }
};

struct Segment
{
    Point A;
    Point B;
    double length()
    {
        return A.distanceTo(B);
    }
};

int main()
{
    Segment s;
    cout << "Enter coordinates for point A: ";
    s.A.read();
    cout << "Enter coordinates for point B: ";
    s.B.read();

    cout << "Length of segment is: " << s.length() << endl;

    return 0;
}