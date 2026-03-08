#include "tasks.h"
#include "circle.h"

double ropeGap() {
  const double earthRadius = 6378100.0; // метры

  Circle earth(earthRadius);
  double oldFerence = earth.getFerence();

  earth.setFerence(oldFerence + 1.0);

  return earth.getRadius() - earthRadius;
}

double poolTotalCost() {
  const double poolRadius = 3.0;
  const double pathWidth = 1.0;

  const double concreteCost = 1000.0;
  const double fenceCost = 2000.0;

  Circle pool(poolRadius);
  Circle outer(poolRadius + pathWidth);

  double pathArea = outer.getArea() - pool.getArea();
  double pathPrice = pathArea * concreteCost;

  double fencePrice = outer.getFerence() * fenceCost;

  return pathPrice + fencePrice;
}