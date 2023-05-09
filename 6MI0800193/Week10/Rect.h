#ifndef _RECT
#define _RECT
#include "Shape.h"
class Rectangle : public Shape
{
private:
	Point get_leftmost_point() const
	{
		Point current = get_point(0);
		for (size_t i = 1; i < 4; i++)
		{
			Point other = get_point(i);
			if (current.x > other.x)
				current = other;
		}
		return current;
	}

	Point get_rightmost_point() const
	{
		Point current = get_point(0);
		for (size_t i = 1; i < 4; i++)
		{
			Point other = get_point(i);
			if (current.x < other.x)
				current = other;
		}
		return current;
	}

	Point get_upmost_point() const
	{
		Point current = get_point(0);
		for (size_t i = 1; i < 4; i++)
		{
			Point other = get_point(i);
			if (current.y < other.y)
				current = other;
		}
		return current;
	}

	Point get_downmost_point() const
	{
		Point current = get_point(0);
		for (size_t i = 1; i < 4; i++)
		{
			Point other = get_point(i);
			if (current.y > other.y)
				current = other;
		}
		return current;
	}
public:
	~Rectangle() = default;
	Rectangle() : Shape(4)
	{

	}

	Rectangle(Point a, Point b, Point c, Point d) : Shape(4)
	{
		this->set_point(0, a);
		this->set_point(1, b);
		this->set_point(2, c);
		this->set_point(3, d);
		count+=4;
	}

	Shape* clone() const
	{
		return new Rectangle(*this);
	}

	double get_side(int pos1, int pos2) const
	{
		Point o = get_point(pos1);
		Point t = get_point(pos2);
		return o.get_dist_to(t);
	}

	double get_area() const override
	{
		double side_a = get_side(0,1);
		double side_b = get_side(1,2);
		return side_a * side_b;
	}

	double get_perimeter() const override
	{
		double side_a = get_side(0, 1);
		double side_b = get_side(1, 2);
		return 2 * (side_a + side_b);
	}

	bool is_point_inside(Point p) const override
	{
		return 	get_leftmost_point().x < p.x && 
			get_rightmost_point().x > p.x &&
			get_upmost_point().y > p.y && 
			get_downmost_point().y < p.y;
	}

};

#endif // !_RECT
