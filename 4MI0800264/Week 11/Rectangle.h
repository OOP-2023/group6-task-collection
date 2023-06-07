#pragma once
#include "Shape.h"

class Rectangle : public Shape
{
	double a;
	double b;

public:

	bool shapeIsRectangle();

	Rectangle(Point pA, Point pB, Point pC, Point pD);

	double getArea();
	double getPerimeter();
	bool checkIfPointIsIn(Point inputPoint);
};