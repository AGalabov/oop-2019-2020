#include <iostream>

double polynomial1(int x)
{
  return x * x + 2 * x - 1;
}

double polynomial2(int x)
{
  return -(x * x * x) + 4 * x - 5;
}

double maximumInInterval(int a, int b, double (*f)(int))
{
  double max = f(a);
  double currMax;

  for (int i = a + 1; i <= b; ++i)
  {
    currMax = f(i);
    if (currMax > max)
    {
      max = currMax;
    }
  }

  return max;
}

int main()
{
  int a, b;
  std::cin >> a >> b;

  std::cout << maximumInInterval(a, b, polynomial1) << std::endl;

  std::cout << maximumInInterval(a, b, polynomial2) << std::endl;

  return 0;
}