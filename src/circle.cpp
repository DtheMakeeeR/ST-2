// Copyright 2022 UNN-CS
#include "circle.h"
#include <cmath>
#include <cstdint>

Circle::Circle(double r) { setRadius(r); }
void Circle::setRadius(double r) {
  if (r <= 0)
    r = 1;
  radius = r;
  ference = 2 * PI * radius;
  area = PI * radius * radius;
}
void Circle::setFerence(double f) {
  if (f <= 0)
    f = 2 * PI;
  ference = f;
  radius = ference / (2 * PI);
  area = PI * radius * radius;
}
void Circle::setArea(double a) {
  if (a <= 0)
    a = PI;
  area = a;
  radius = sqrt(area / PI);
  ference = 2 * PI * radius;
}
