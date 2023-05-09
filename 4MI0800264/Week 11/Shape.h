#pragma once
#include <iostream>
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"

struct Point
{
	int x;
	int y;
};

class Shape
{
protected:
	Point* points;
	unsigned count;


public:

	Shape(unsigned inputCount);

	~Shape();

	void setPoint(unsigned position, Point inputPoint);

	virtual double getArea() = 0;
	virtual double getPerimeter() = 0;
	virtual bool checkIfPointIsIn(Point inputPoint) = 0;

	double getDist(Point p1, Point p2);
};