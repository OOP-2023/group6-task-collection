#ifndef _SHAPE
#define _SHAPE
#include <math.h>
#include <iostream>
const double PI = 3.1415;
struct Point
{
	double x;
	double y;

	double get_dist_to(Point other)
	{
		double dist_x = abs(x - other.x);
		double dist_y = abs(y - other.y);
		return sqrt(dist_x * dist_x + dist_y * dist_y);
	}
};

class Shape
{
private:
	Point* points;

	size_t size;
public:
	size_t count;
	virtual ~Shape()
	{
		delete[] points;
	}

	virtual Shape* clone() const = 0;

	Shape(int size)
	{
		points = new Point[size];
		this->size = size;
		this->count = 0;
	}

	Shape(const Shape& other)
	{
		this->size = other.size;
		this->count = other.count;
		points = new Point[size];

		for (size_t i = 0; i < size; i++)
		{
			points[i] = other.points[i];
		}
	}

	Point get_point(int pos) const
	{
		if (pos < 0 || pos >= size)
			return { 0,0 };

		return points[pos];
	}

	int get_count() const
	{
		return count;
	}

	int get_size() const
	{
		return size;
	}

	void set_point(int pos, Point point)
	{
		if (pos < 0 || pos >= size)
			return;

		points[pos] = point;
	}

	virtual double get_area() const = 0;
	
	virtual double get_perimeter() const = 0;

	virtual bool is_point_inside(Point p) const = 0;

	void print() const
	{
		std::cout << "Area: " << get_area() << "; Perimeter: " << get_perimeter() << std::endl;
	}
};

#endif // !_SHAPE
