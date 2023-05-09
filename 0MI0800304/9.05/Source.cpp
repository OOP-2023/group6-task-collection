#include<iostream>
#include <math.h>

const double PI = 3.14159265359;
struct Point
{
	double x;
	double y;

};

class Shape {
public:
	Shape(unsigned numOfPoints) {
		points = new Point[numOfPoints];
		size = numOfPoints;
	}
	~Shape() {
		delete[] points;
	}

	virtual void setPoint()=0;
	virtual void getArea() = 0;
	virtual void getPer() = 0;

protected:
	Point* points;
	unsigned size;

};
class Circle :public Shape {
	public:
		Circle(Point _pointCenter, Point _pointOnCircle):Shape(2) {
			points[0] = _pointCenter;
			points[1] = _pointOnCircle;
			pointCenter = _pointCenter;
			pointOnCircle = _pointOnCircle;
			radius = sqrt((pointCenter.x - pointOnCircle.x) * (pointCenter.x - pointOnCircle.x) +
				(pointCenter.y - pointOnCircle.y) * (pointCenter.y - pointOnCircle.y));

		}
		double getArea()const {
			return PI * radius * radius;
		}
		double getPer() const {
			return 2 * PI * radius;
		}
		
private:

	Point pointCenter;
	Point pointOnCircle;
	double radius;

};


//class Entity {
//public:
//	virtual void f() {
//		std::cout << "E::f" << std::endl;
//	}
//};
//
//class Der : public Entity {
//public:
//	void f() {
//		std::cout << "D::f" << std::endl;
//	}
//};

int main() {
	
}