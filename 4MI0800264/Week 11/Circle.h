#pragma once
#include "Shape.h"

class Circle : public Shape
{
	unsigned radius;
	const double pi = 3.1415;

public:

	Circle(Point centre, unsigned inputRadius);

	double getArea();
	double getPerimeter();
	bool checkIfPointIsIn(Point inputPoint);

};