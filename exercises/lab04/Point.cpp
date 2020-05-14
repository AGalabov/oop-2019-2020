#include "Point.h"

Point::Point()
{
  this->size = 0;
  this->coordinates = nullptr;
}

Point::Point(double *coords, size_t sz)
{
  this->size = sz;
  this->coordinates = new double[size];

  for (size_t i = 0; i < sz; i++)
  {
    coordinates[i] = coords[i];
  }
}

Point::~Point()
{
  delete[] coordinates;
}

Point::Point(const Point &other)
{
  this->size = other.getSize();
  this->coordinates = new double[size];

  double *otherCoords = other.getCoords();
  for (size_t i = 0; i < size; i++)
  {
    coordinates[i] = otherCoords[i];
  }
}

double *Point::getCoords() const
{
  return this->coordinates;
}

size_t Point::getSize() const
{
  return this->size;
}

Point &Point::operator=(const Point &other)
{
  if (this != &other)
  {
    if (other.size != size)
    {
      delete[] coordinates;
      size = 0;
      coordinates = nullptr;
      coordinates = new double[other.size];
      size = other.size;
    }

    for (size_t i = 0; i < size; i++)
    {
      coordinates[i] = other.coordinates[i];
    }
  }

  return *this;
}

void printArray(double *arr, size_t sz)
{
  for (size_t i = 0; i < sz; i++)
  {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

int main()
{
  double coords1[2] = {2.5, 3};
  double coords2[2] = {3, 6};

  Point p1;
  Point p2(coords1, 2);

  printArray(p1.getCoords(), p1.getSize());
  printArray(p2.getCoords(), p2.getSize());

  p1 = p2;
  printArray(p1.getCoords(), p1.getSize());

  Point p3(p1);
  printArray(p3.getCoords(), p3.getSize());
  return 0;
}