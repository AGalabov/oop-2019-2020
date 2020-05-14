#include <iostream>
#include <math.h>
#include "helperFunctions.h"

double p1Norm(double *coordinates, size_t dim)
{
  double sum = 0;

  for (size_t i = 0; i < dim; ++i)
  {
    sum += coordinates[i];
  }

  return sum;
}

double p2Norm(double *coordinates, size_t dim)
{
  double sumSq = 0;

  for (size_t i = 0; i < dim; ++i)
  {
    sumSq += (coordinates[i] * coordinates[i]);
  }

  return sqrt(sumSq);
}

struct Point
{
  double *coordinates;
  size_t dimension;

  Point()
  {
    coordinates = nullptr;
    dimension = 0;
  }

  Point(double *coordArr, size_t sz)
  {
    coordinates = new double(sz);

    copyInSameSizeArrays(coordArr, coordinates, sz);

    dimension = sz;
  }

  void assignNewCoordinates(double *coordArr, size_t sz)
  {
    if (sz != dimension)
    {
      delete[] coordinates;
      coordinates = new double[sz];
      dimension = sz;
    }

    copyInSameSizeArrays(coordArr, coordinates, sz);
  }

  double calcDistance(const Point &otherPoint, double (*norm)(double *, size_t dim))
  {
    if (otherPoint.dimension != dimension)
    {
      return -1;
    }

    double *arrayForNorm = new double[dimension];
    for (size_t i = 0; i < dimension; ++i)
    {
      arrayForNorm[i] = fabs(coordinates[i] - otherPoint.coordinates[i]);
    }

    double answer = norm(arrayForNorm, dimension);

    delete[] arrayForNorm;
    return answer;
  }

  ~Point()
  {
    delete[] coordinates;
  }
};

int main()
{

  //example - https://en.wikipedia.org/wiki/Taxicab_geometry#/media/File:Manhattan_distance.svg
  double p1Coordinates[] = {0, 0};
  double p2Coordinates[] = {6, 6};

  Point p1(p1Coordinates, 2);
  Point p2(p2Coordinates, 2);

  std::cout << p1.calcDistance(p2, p1Norm) << std::endl;
  std::cout << p2.calcDistance(p1, p2Norm) << std::endl;
  return 0;
}