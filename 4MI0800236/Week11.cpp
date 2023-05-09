// Week11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<exception>

struct Point {
	double x;
	double y;
};

class Shape {
protected:
	Point* points;
	size_t numberOfPoints;
public:
	Shape(size_t numberOfPoints) :numberOfPoints(numberOfPoints) {
		points = new Point[numberOfPoints];
	}

	virtual ~Shape() {
		delete[] points;
	}

	void setPoint(size_t index, const Point& point) {
		if (index >= numberOfPoints) {
			throw std::exception("Out of index");
		}
		points[index] = point;
	}

	virtual double area() const = 0;
	virtual double perimeter() const = 0;
	virtual bool contains(const Point& point) const = 0;
};

class Circle :public Shape {
private:
	double radius;
public:
	Circle(const Point& center, double radius):Shape(1), radius(radius) {
		setPoint(0, center);
	} 
	
	double area() const override {
		return  3.14 * radius * radius;
	}

	double perimeter() const override {
		return 2 * 3.14 * radius;
	}

	bool contains(const Point& point) const override {
		double dx = point.x - points[0].x;
		double dy = point.y - points[0].y;
		double distance = sqrt(dx * dx + dy * dy);
		return distance <= radius;
	}
};

class Triangle : public Shape {
public:
	Triangle(const Point& p1, const Point& p2, const Point& p3) :Shape(3) {
		setPoint(0, p1);
		setPoint(1, p2);
		setPoint(2, p3);
	}

	double area() const override {
		double a = sqrt((points[0].x - points[1].x) * (points[0].x - points[1].x) + (points[0].y - points[1].y) * (points[0].y - points[1].y));
		double b = sqrt((points[1].x - points[2].x) * (points[1].x - points[2].x) + (points[1].y - points[2].y) * (points[1].y - points[2].y));
		double c = sqrt((points[2].x - points[0].x) * (points[2].x - points[0].x) + (points[2].y - points[0].y) * (points[2].y - points[0].y));
		double halfperimeter = (a + b + c) / 2;
		double area = sqrt(halfperimeter * (halfperimeter - a) * (halfperimeter - b) * (halfperimeter - c));
		return area;
	}

	double perimeter() const override {
		double a = sqrt((points[0].x - points[1].x) * (points[0].x - points[1].x) + (points[0].y - points[1].y) * (points[0].y - points[1].y));
		double b = sqrt((points[1].x - points[2].x) * (points[1].x - points[2].x) + (points[1].y - points[2].y) * (points[1].y - points[2].y));
		double c = sqrt((points[2].x - points[0].x) * (points[2].x - points[0].x) + (points[2].y - points[0].y) * (points[2].y - points[0].y));
		double perimeter = a + b + c;
		return perimeter;
	}



	
};
int main()
{
	Shape* s = new Circle({ 0, 0 }, 5);

	try {
		s->setPoint(100, { 0, 0 });
	}
	catch (const std::exception& e) {
		e.what();
	}
}


