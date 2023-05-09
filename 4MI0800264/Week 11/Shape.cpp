#include "Shape.h"

Shape::Shape(unsigned inputCount)
{
	count = inputCount;
	points = new Point[count];
}

Shape::~Shape()
{
	std::cout << "~Shape \n";
	delete[] points;
}

void Shape::setPoint(unsigned position, Point inputPoint)
{
	if (position >= count)
		throw std::runtime_error("You have entered invalid Position! \n");

	points[position].x = inputPoint.x;
	points[position].y = inputPoint.y;
}

double Shape::getDist(Point p1, Point p2)
{
	double dx = abs(p1.x - p2.x);
	double dy = abs(p1.y - p2.y);

	return sqrt((dx * dx) + (dy * dy));
}
