#include <iostream>
using namespace std;

class Shape
{
private:
	struct point
	{
		int x = 0;
		int y = 0;
	};
public:

	Shape(int _number);
	virtual ~Shape();
	Shape(const Shape& other);
	Shape& operator=(const Shape& other);
	void changePoint(size_t position, int _x, int _y);
	double distance(point point1, point point2);
	virtual int area(const Shape& other);
	virtual int perimeter(const Shape& other);
	virtual bool isInArea();

private:
	
	point* points;
	size_t number;
	void copyFrom(const Shape& other);
	void free();
};

Shape::Shape(int _number)
{
	 number = _number;
	 points = new point [number];
}

Shape::~Shape()
{
	free();
}
Shape::Shape(const Shape& other)
{
	free();
	copyFrom(other);
}
Shape& Shape::operator=(const Shape& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}
void Shape::copyFrom(const Shape& other)
{
	number = other.number;
	points = new point[number];
	for (int i = 0; i < number; i++)
	{
		points[i] = other.points[i];
	}
}
void Shape::free()
{
	delete[] points;
}
void Shape::changePoint(size_t position, int _x, int _y)
{
	points[position].x = _x;
	points[position].y = _y;
}
double Shape::distance(point point1, point point2)
{
	double dist = (point2.x - point1.x) * (point2.x - point1.x) + (point2.y - point1.y) * (point2.y - point1.y);
	dist = sqrt(dist);
	return dist;
}
int Shape::area(const Shape& other)
{
	return 0;
}
int Shape::perimeter(const Shape& other)
{
	int perim = 0;
	for (int i = 0; i < other.number; i++)
	{
		for (int j = 1; j < other.number; j++)
		{
			perim += distance(other.points[i], other.points[j]);
		}
	}
	return perim;
}

bool Shape::isInArea()
{
	return false;
}

class Circle : public Shape
{
public:
	int area(const Shape& other) override;
	int perimeter(const Shape& other)override;
	bool isInArea()override;
private:

};
int Circle::area(const Shape& other)
{
	return 0;
}

int Circle::perimeter(const Shape& other)
{
	return 0;
}

bool Circle::isInArea()
{
	return false;
}
class Triangle : public Shape
{
public:
	int area(const Shape& other) override;
	bool isInArea()override;
private:

};
int Triangle::area(const Shape& other)
{
	return 0;
}


bool Triangle::isInArea()
{
	return false;
}
class Rectangle : public Shape
{
public:
	int area(const Shape& other) override;
	bool isInArea()override;
private:

};

int Rectangle::area(const Shape& other)
{
	return 0;
}

bool Rectangle::isInArea()
{
	return false;
}
