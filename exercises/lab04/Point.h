#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

#include <iostream>

class Point
{
  double *coordinates;
  size_t size;

public:
  Point();
  ~Point();
  Point(double *, size_t);
  Point(const Point &);

  double *getCoords() const;
  size_t getSize() const;

  Point &operator=(const Point &);
};

#endif