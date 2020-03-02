#include<iostream>

using doubleFrom3Ints = double (*)(int, int, int);
using intFromInt = int(*)(int);

int next(int number)
{
    return number + 1;
}

double sum(int start, int end, doubleFrom3Ints term, intFromInt next, int otherEnd, int a)
{
    double s = 0;
    for (int i = start; i <= end; i = next(i))
    {
        s += term(i, otherEnd, a);
    }

    return s;
}

double prod(int start, int end, doubleFrom3Ints term, intFromInt next, int i, int a)
{
    double prod = 1;
    for (int j = start; j <= end; j = next(j))
    {
        prod *= term(a, i, j);
    }

    return prod;
}

double func(int a, int i, int j)
{
    return ((double)(a + j) / (double)(i + j));
}

double helper(int i, int b, int a)
{
    return prod(1, b, func, next, i, a);
}

double answerFunction(int n, int m, int a)
{
    return sum(1, n, helper, next, m, a);
}

int main()
{
    int n, m, a;
    std::cin >> n >> m >> a;

    std::cout << answerFunction(n, m, a) << std::endl;
}

