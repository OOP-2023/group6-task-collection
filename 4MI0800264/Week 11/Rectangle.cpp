#include "Rectangle.h"

bool Rectangle::shapeIsRectangle()
{
	Triangle temp1(points[0], points[1], points[2]);
	Triangle temp2(points[0], points[3], points[2]);

	bool angleAtBIsRight = (temp1.getArea() == getDist(points[0], points[1]) * getDist(points[1], points[2]));
	bool angleAtDIsRight = (temp2.getArea() == getDist(points[0], points[3]) * getDist(points[3], points[2]));

	return angleAtBIsRight && angleAtDIsRight;
}

Rectangle::Rectangle(Point pA, Point pB, Point pC, Point pD) : Shape(4)
{
	setPoint(0, pA);
	setPoint(1, pB);
	setPoint(2, pC);
	setPoint(3, pD);

	a = getDist(pA, pB);
	b = getDist(pB, pC);

	if (!shapeIsRectangle())
		throw std::runtime_error("Shape is not a rectangle!");
}

double Rectangle::getArea()
{
	return a * b;
}

double Rectangle::getPerimeter()
{
	return 2 * (a + b);
}

bool Rectangle::checkIfPointIsIn(Point inputPoint)
{
	bool xIsIn = (inputPoint.x > points[0].x && inputPoint.x < points[2].x) ||
		(inputPoint.x < points[0].x&& inputPoint.x > points[2].x);

	bool yIsIn = (inputPoint.y > points[1].y && inputPoint.y < points[3].y) ||
		(inputPoint.y < points[1].y && inputPoint.y > points[3].y);

	return xIsIn && yIsIn;
}