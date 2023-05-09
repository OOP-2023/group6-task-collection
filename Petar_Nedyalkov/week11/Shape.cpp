#include <iostream>
#include <cmath>
#include "Shape.hpp"

const double PI = 3.1415;

//class Shape
void Shape::setPoint(int _x, int _y) {
	
	if (index == capacity)
		return; //no space
	else {
		points[index].x = _x;
		points[index++].y = _y;
	}

	//checking if I added the last point, and then to find all the sides of the figure
	if (index == capacity)
		setSides();

}

Shape::Shape(size_t cap)
{
	capacity = cap;
	index = 0;
	points = new Point[capacity];
}

Shape::~Shape()
{
	delete[] points;
}
//--------------


// class Circle

Circle::Circle(size_t cap) : Shape(cap) {

}

void Circle::setSides() {

	int dx = abs(points[0].x - points[1].x);
	int dy = abs(points[0].y - points[1].y);
	radius = sqrt(dx * dx + dy * dy);
}

double Circle::getArea() {

	return 2 * PI * radius;
}

double Circle::getPerm() {

	return PI * radius * radius;
}
//------------

//class Rect

Rectagnle::Rectagnle(size_t cap) : Shape(cap) {

}

void Rectagnle::setSides() {
	
	int firstSide = abs(points[0].x - points[1].x);
	int secondSide = abs(points[0].y - points[1].y);
	
	bigSide = (firstSide > secondSide) ? firstSide : secondSide;
	smallSide = (firstSide < secondSide) ? firstSide : secondSide;
}
double Rectagnle::getArea() {

	return bigSide * smallSide;
}

double Rectagnle::getPerm() {

	return 2*smallSide + 2*bigSide;
}
//------

//class Triangle

Triangle::Triangle(size_t cap) : Shape(cap) {

}

void Triangle::setSides() {
	int dx, dy;

	dx = abs(points[0].x - points[1].x);
	dy = abs(points[0].y - points[1].y);
	firstSide = sqrt(dx * dx + dy * dy);

	dx = abs(points[1].x - points[2].x);
	dy = abs(points[1].y - points[2].y);
	secondSide = sqrt(dx * dx + dy * dy);

	dx = abs(points[0].x - points[2].x);
	dy = abs(points[0].y - points[2].y);
	thirdSide = sqrt(dx * dx + dy * dy);
}
double Triangle::getArea() {

	double halfPerm = getPerm() / 2;
	return sqrt(halfPerm * (halfPerm - firstSide) * (halfPerm - secondSide) * (halfPerm - thirdSide)));
}

double Triangle::getPerm() {

	return firstSide + secondSide + thirdSide;
}
	
int main()
{
	Triangle myShape(3);
	myShape.setPoint(0, 0);
	myShape.setPoint(0, 4);
	myShape.setPoint(3, 0);

	std::cout << myShape.getArea()<<std::endl;
	std::cout<<myShape.getPerm()<<std::endl;

	Circle myShape2(2);
	myShape2.setPoint(0, 0);
	myShape2.setPoint(0, 5);
	std::cout << myShape2.getArea() << std::endl;
	std::cout << myShape2.getPerm() << std::endl;


}
