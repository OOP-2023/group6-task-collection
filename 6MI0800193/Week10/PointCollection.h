#ifndef _POINT_COLLECT
#define _POINT_COLLECT
#include "Shape.h"
#include "Circle.h"
#include "Rect.h"
#include "Triangle.h"
#include <vector>
#include <ostream>
#include <iostream>
#include <iomanip>

class PointCollection
{
private:
	std::vector<Shape*> shapes;
public:
	~PointCollection()
	{
		for (size_t i = 0; i < shapes.size(); i++)
		{
			delete shapes[i];
		}
	}
	PointCollection() = default;

	PointCollection(const PointCollection& other)
	{
		for (size_t i = 0; i < other.get_len(); i++)
		{
			shapes.push_back(other.shapes[i]->clone());
		}
	}

	void add_triangle(Point a, Point b, Point c)
	{
		shapes.push_back(new Triangle(a, b, c));
	}

	void add_rectangle(Point a, Point b, Point c, Point d)
	{
		shapes.push_back(new Rectangle(a, b, c, d));
	}

	void add_circle(Point center, Point side)
	{
		shapes.push_back(new Circle(center, side));
	}

	size_t get_len() const
	{
		return shapes.size();
	}

	void print_areas(std::ostream& out) const
	{
		for (size_t i = 0; i < shapes.size(); i++)
		{
			out << "Area (" << i << "): " << std::fixed << std::setprecision(2) << shapes[i]->get_area() << std::endl;
		}
	}

	void print_perimeters(std::ostream& out) const
	{
		for (size_t i = 0; i < shapes.size(); i++)
		{
			out << "Perimeter (" << i << "): " << std::fixed <<std::setprecision(2) << shapes[i]->get_perimeter() << std::endl;
		}
	}


};

#endif // !_POINT_COLLECT
