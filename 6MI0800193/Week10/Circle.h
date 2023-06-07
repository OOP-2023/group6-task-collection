#ifndef _CIRCLE
#define _CIRCLE

#include "Shape.h"

class Circle : public Shape
{
private:
public:
	~Circle() = default;
	Circle() : Shape(2)
	{

	}
	Shape* clone() const
	{
		return new Circle(*this);
	}

	Circle(Point center, Point side) : Shape(2)
	{
		this->set_point(0, center);
		count++;
		this->set_point(1, side);
		count++;
	}

	double get_radius() const
	{
		return get_point(0).get_dist_to(get_point(1));
	}

	double get_area() const override
	{
		double radius = get_radius();
		return PI * radius * radius;
	}

	double get_perimeter() const override
	{
		double radius = get_radius();
		return 2 * PI * radius;
	}

	bool is_point_inside(Point p) const override
	{
		double dist_to_point = get_point(0).get_dist_to(p);
		double dist_to_rad = get_radius();

		return dist_to_point < dist_to_rad;
	}
};


#endif // !_CIRCLE
