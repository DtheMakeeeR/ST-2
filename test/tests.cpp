// Copyright 2025 UNN-CS Team
#include <math.h>

#include <cmath>

#include <gtest/gtest.h>

#include "Circle.h"
#include "tasks.h"

static const double EPS = 1e-9;

TEST(CircleCtor, DefaultCtor) {
  Circle c;
  EXPECT_NEAR(c.getRadius(), 1.0, EPS);
  EXPECT_NEAR(c.getFerence(), 2 * PI, EPS);
  EXPECT_NEAR(c.getArea(), PI, EPS);
}

TEST(CircleCtor, PositiveCtor) {
  Circle c(2.0);
  EXPECT_NEAR(c.getRadius(), 2.0, EPS);
  EXPECT_NEAR(c.getFerence(), 4 * PI, EPS);
  EXPECT_NEAR(c.getArea(), 4 * PI, EPS);
}

TEST(CircleCtor, InvalidCtor) {
  Circle c(-5.0);
  EXPECT_NEAR(c.getRadius(), 1.0, EPS);
  EXPECT_NEAR(c.getFerence(), 2 * PI, EPS);
  EXPECT_NEAR(c.getArea(), PI, EPS);
}

TEST(CircleRadius, RadiusSet) {
  Circle c;
  c.setRadius(3.0);
  EXPECT_NEAR(c.getRadius(), 3.0, EPS);
  EXPECT_NEAR(c.getFerence(), 6 * PI, EPS);
  EXPECT_NEAR(c.getArea(), 9 * PI, EPS);
}

TEST(CircleRadius, RadiusZero) {
  Circle c(5.0);
  c.setRadius(0.0);
  EXPECT_NEAR(c.getRadius(), 1.0, EPS);
  EXPECT_NEAR(c.getFerence(), 2 * PI, EPS);
  EXPECT_NEAR(c.getArea(), PI, EPS);
}

TEST(CircleRadius, RadiusNeg) {
  Circle c(5.0);
  c.setRadius(-7.0);
  EXPECT_NEAR(c.getRadius(), 1.0, EPS);
  EXPECT_NEAR(c.getFerence(), 2 * PI, EPS);
  EXPECT_NEAR(c.getArea(), PI, EPS);
}

TEST(CircleRadius, RadiusChange) {
  Circle c(2.0);
  c.setRadius(4.0);
  EXPECT_NEAR(c.getRadius(), 4.0, EPS);
  EXPECT_NEAR(c.getFerence(), 8 * PI, EPS);
  EXPECT_NEAR(c.getArea(), 16 * PI, EPS);
}

TEST(CircleRadius, RadiusAfterArea) {
  Circle c(2.0);
  c.setArea(16.0 * PI);
  c.setRadius(2.5);
  EXPECT_NEAR(c.getRadius(), 2.5, EPS);
  EXPECT_NEAR(c.getFerence(), 5.0 * PI, EPS);
  EXPECT_NEAR(c.getArea(), 6.25 * PI, EPS);
}

TEST(CircleFerence, FerenceSet) {
  Circle c;
  c.setFerence(8.0 * PI);
  EXPECT_NEAR(c.getFerence(), 8.0 * PI, EPS);
  EXPECT_NEAR(c.getRadius(), 4.0, EPS);
  EXPECT_NEAR(c.getArea(), 16.0 * PI, EPS);
}

TEST(CircleFerence, FerenceZero) {
  Circle c(3.0);
  c.setFerence(0.0);
  EXPECT_NEAR(c.getFerence(), 2 * PI, EPS);
  EXPECT_NEAR(c.getRadius(), 1.0, EPS);
  EXPECT_NEAR(c.getArea(), PI, EPS);
}

TEST(CircleFerence, FerenceNeg) {
  Circle c(3.0);
  c.setFerence(-10.0);
  EXPECT_NEAR(c.getFerence(), 2 * PI, EPS);
  EXPECT_NEAR(c.getRadius(), 1.0, EPS);
  EXPECT_NEAR(c.getArea(), PI, EPS);
}

TEST(CircleFerence, FerenceChange) {
  Circle c(2.0);
  c.setFerence(10.0 * PI);
  EXPECT_NEAR(c.getFerence(), 10.0 * PI, EPS);
  EXPECT_NEAR(c.getRadius(), 5.0, EPS);
  EXPECT_NEAR(c.getArea(), 25.0 * PI, EPS);
}

TEST(CircleFerence, FerenceAfterRadius) {
  Circle c(2.0);
  c.setRadius(7.0);
  c.setFerence(6.0 * PI);
  EXPECT_NEAR(c.getFerence(), 6.0 * PI, EPS);
  EXPECT_NEAR(c.getRadius(), 3.0, EPS);
  EXPECT_NEAR(c.getArea(), 9.0 * PI, EPS);
}

TEST(CircleArea, AreaSet) {
  Circle c;
  c.setArea(25.0 * PI);
  EXPECT_NEAR(c.getArea(), 25.0 * PI, EPS);
  EXPECT_NEAR(c.getRadius(), 5.0, EPS);
  EXPECT_NEAR(c.getFerence(), 10.0 * PI, EPS);
}

TEST(CircleArea, AreaZero) {
  Circle c(4.0);
  c.setArea(0.0);
  EXPECT_NEAR(c.getArea(), PI, EPS);
  EXPECT_NEAR(c.getRadius(), 1.0, EPS);
  EXPECT_NEAR(c.getFerence(), 2 * PI, EPS);
}

TEST(CircleArea, AreaNeg) {
  Circle c(4.0);
  c.setArea(-9.0);
  EXPECT_NEAR(c.getArea(), PI, EPS);
  EXPECT_NEAR(c.getRadius(), 1.0, EPS);
  EXPECT_NEAR(c.getFerence(), 2 * PI, EPS);
}

TEST(CircleArea, AreaChange) {
  Circle c(2.0);
  c.setArea(4.0 * PI);
  EXPECT_NEAR(c.getArea(), 4.0 * PI, EPS);
  EXPECT_NEAR(c.getRadius(), 2.0, EPS);
  EXPECT_NEAR(c.getFerence(), 4.0 * PI, EPS);
}

TEST(CircleArea, AreaAfterFerence) {
  Circle c(2.0);
  c.setFerence(12.0 * PI);
  c.setArea(9.0 * PI);
  EXPECT_NEAR(c.getArea(), 9.0 * PI, EPS);
  EXPECT_NEAR(c.getRadius(), 3.0, EPS);
  EXPECT_NEAR(c.getFerence(), 6.0 * PI, EPS);
}

TEST(CircleTask, RopeGap) { EXPECT_NEAR(ropeGap(), 1.0 / (2.0 * PI), EPS); }

TEST(CircleTask, PoolCost) { EXPECT_NEAR(poolTotalCost(), 23000.0 * PI, EPS); }
