#include "Circle.h"

Circle::Circle(Point centre, unsigned inputRadius) : Shape(1)
{
	setPoint(0, centre);
	radius = inputRadius;
}

double Circle::getArea()
{
	return pi * radius * radius;
}

double Circle::getPerimeter()
{
	return pi * radius;
}

bool Circle::checkIfPointIsIn(Point inputPoint)
{
	return radius >= getDist(inputPoint, points[0]);
}