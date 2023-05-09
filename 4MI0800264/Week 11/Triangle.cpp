#include "Triangle.h"

Triangle::Triangle(Point pA, Point pB, Point pC) : Shape(3)
{
	setPoint(0, pA);
	setPoint(1, pB);
	setPoint(2, pC);

	a = getDist(pB, pC);
	b = getDist(pA, pC);
	c = getDist(pA, pB);
}

double Triangle::getArea()
{
	double halfPerimeter = (a + b + c) / 2;

	return sqrt(halfPerimeter * (halfPerimeter - a) * (halfPerimeter - b) * (halfPerimeter - c));
}

double Triangle::getPerimeter()
{
	return a + b + c;
}

bool Triangle::checkIfPointIsIn(Point inputPoint)
{
	Triangle temp1 (points[0], points[1], inputPoint);
	Triangle temp2 (points[1], points[2], inputPoint);
	Triangle temp3 (points[0], points[2], inputPoint);

	return this->getArea() == temp1.getArea() + temp2.getArea() + temp3.getArea();
}