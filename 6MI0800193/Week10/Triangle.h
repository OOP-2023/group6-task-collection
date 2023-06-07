#ifndef _TRIANGLE
#define _TRIANGLE
#include "Shape.h"
class Triangle : public Shape
{
public:
	~Triangle() = default;
	Triangle() : Shape(3)
	{

	}

	Triangle(Point a, Point b, Point c) : Shape(3)
	{
		this->set_point(0, a);
		this->set_point(1, b);
		this->set_point(2, c);
		count += 3;
	}

	Shape* clone() const
	{
		return new Triangle(*this);
	}

	double get_side(int a, int b) const
	{
		return get_point(a).get_dist_to(get_point(b));
	}

	double get_area() const override
	{
		double side_a = get_side(0, 1);
		double side_b = get_side(1, 2);
		double side_c = get_side(2, 3);
		double p = get_perimeter() / 2;
		return sqrt(p * (p - side_a) * (p - side_b) * (p - side_c));
	}

	double get_perimeter() const override
	{
		double side_a = get_side(0, 1);
		double side_b = get_side(1, 2);
		double side_c = get_side(2, 3);
		return side_a + side_b + side_c;
	}

	bool is_point_inside(Point p) const override
	{
		return false;
	}
};

#endif // !_TRIANGLE
