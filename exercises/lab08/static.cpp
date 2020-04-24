#include <iostream>

class Math
{
public:
    static const double PI;
    static const double E;

    static double pow(double, int);
    static double abs(double);
};

const double Math::PI = 3.141592;
const double Math::E = 2.71828;

double Math::abs(double num)
{
    if (num < 0)
        return -1 * num;
    return num;
}

double Math::pow(double num, int power)
{
    if (power == 0)
        return 1;

    bool isPositive = power > 0;
    double acc = isPositive ? num : (1 / num);

    for (int i = 1; i < abs(power); i++)
    {
        if (isPositive)
        {
            acc *= num;
        }
        else
        {
            acc /= num;
        }
    }
    return acc;
}

int main()
{
    std::cout << Math::pow(Math::PI, 3);

    return 0;
}