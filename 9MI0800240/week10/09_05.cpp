// 09_05.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Shape
{
public:
	struct Point
	{
		double _x;
		double _y;
	};


protected:
	Point* _points = nullptr;
	size_t _pointCount = 0;

	void copy(const Shape& t)
	{
		_pointCount = t._pointCount;

		for (size_t i = 0; i < t._pointCount; i++)
		{
			_points[i] = t._points[i];
		}
	}
	void free()
	{
		delete[] _points;
		_points = nullptr;
	}


public:

	double getDistance(Point p1, Point p2) const
	{
		return sqrt((p2._x - p1._x) * (p2._x - p1._x) + (p2._y - p1._y) * (p2._y - p1._y));
	}

	Shape()
	{
		_points = nullptr;
	}

	Shape(size_t pointCount)
	{
		Point* figure = new Point[pointCount];
		_pointCount = pointCount;
	}

	Shape(const Shape& other)
	{
		_pointCount = other._pointCount;
		copy(other);
	}
	Shape& operator=(const Shape& other)
	{
		if (this != &other)
		{
			free();
			copy(other);
		}
		return *this;
	}
	~Shape()
	{
		free();
	}
	void setPoint(size_t index, const Point& point) {
		if (index >= _pointCount) {
			throw std::exception("Out of index");
		}
		_points[index] = point;
	}
	size_t changePoint(double x, double y, size_t position)
	{
		_points[position]._x = x;
		_points[position]._y = y;
	}

	virtual double getArea() const = 0;
	virtual double getPerimeter() const = 0;

	virtual bool isPointInShape() const = 0;

};

class Circle : protected Shape
{
private:
	double _r;
	Point _center;

public:

	Circle() : Shape(1)
	{}
	


	double getArea() const override
	{
		return 3,14 *_r*_r;
	}

	double getPerimeter() const override
	{
		return 2 * 3, 14 * _r;
	}
};


class Triangle : public Shape
{
public:
	Triangle(const Point& p1, const Point& p2, const Point& p3) :Shape(3)
	{
		setPoint(0, p1);
		setPoint(1, p2);
		setPoint(2, p3);
	}



	double getArea() const override
	{
		double a = sqrt((_points[0]._x - _points[1]._x) * (_points[0]._x - _points[1]._x) + (_points[0]._y - _points[1]._y) * (_points[0]._y - _points[1]._y));
		double b = sqrt((_points[1]._x - _points[2]._x) * (_points[1]._x - _points[2]._x) + (_points[1]._y - _points[2]._y) * (_points[1]._y - _points[2]._y));
		double c = sqrt((_points[2]._x - _points[0]._x) * (_points[2]._x - _points[0]._x) + (_points[2]._y - _points[0]._y) * (_points[2]._y - _points[0]._y));
		double halfperimeter = (a + b + c) / 2;
		double area = sqrt(halfperimeter * (halfperimeter - a) * (halfperimeter - b) * (halfperimeter - c));
		return area;
	}

	double getPerimeter() const override
	{
		double a = sqrt((_points[0]._x - _points[1]._x) * (_points[0]._x - _points[1]._x) + (_points[0]._y - _points[1]._y) * (_points[0]._y - _points[1]._y));
		double b = sqrt((_points[1]._x - _points[2]._x) * (_points[1]._x - _points[2]._x) + (_points[1]._y - _points[2]._y) * (_points[1]._y - _points[2]._y));
		double c = sqrt((_points[2]._x - _points[0]._x) * (_points[2]._x - _points[0]._x) + (_points[2]._y - _points[0]._y) * (_points[2]._y - _points[0]._y));
		double perimeter = a + b + c;

		return perimeter;
	}
};


int main()
{
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
