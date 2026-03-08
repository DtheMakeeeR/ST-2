// Copyright 2022 UNN-CS
#ifndef INCLUDE_CIRCLE_H_
#define INCLUDE_CIRCLE_H_
#include <cstdint>

double const PI = 3.14159;

class Circle {
  double radius;
  double ference;
  double area;

public:
  Circle(double r = 1.0);
  double getRadius() const { return radius; }
  double getFerence() const { return ference; }
  double getArea() const { return area; }
  void setRadius(double r);
  void setFerence(double f);
  void setArea(double a);
};

#endif // INCLUDE_CIRCLE_H_
