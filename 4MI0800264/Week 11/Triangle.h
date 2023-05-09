#pragma once
#include "Shape.h"

class Triangle : public Shape
{
	double a, b, c;

public:

	Triangle(Point pA, Point pB, Point pC);

	double getArea();
	double getPerimeter();
	bool checkIfPointIsIn(Point inputPoint);
};