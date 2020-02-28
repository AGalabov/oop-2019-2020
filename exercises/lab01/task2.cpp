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
    double distanceToCenter()
    {
        return sqrt(sqrt(x * x + y * y) + z * z);
    }
    void print()
    {
        cout << "(" << x << ", " << y << ", " << z << ") ->" << distanceToCenter() << endl;
    }
};

Point closestToCenter(Point points[], int size)
{
    int minIndex = 0;
    double minDist = points[0].distanceToCenter();

    for (int i = 0; i < size; ++i)
    {
        double distance = points[i].distanceToCenter();
        if (distance < minDist)
        {
            minDist = distance;
            minIndex = i;
        }
    }

    return points[minIndex];
}

int main()
{
    int n;
    cout << "n = ";
    cin >> n;

    Point *points = new Point[n];
    for (int i = 0; i < n; ++i)
    {
        points[i].read();
    }

    if (n > 0)
    {
        closestToCenter(points, n).print();
    }

    return 0;
}