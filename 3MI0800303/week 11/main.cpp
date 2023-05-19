#include <iostream>
#include <math.h>
using namespace std;


class Shape {
    public:
        struct Point {
            double x = 0;
            double y = 0;

            double getLength(const Point& other) const{
                return sqrt((other.x - x)*(other.x - x) + (other.y - y)*(other.y - y));
            }
        };

    protected:
        Point* points;
        size_t num_points;
        
    public:
        Shape(size_t n){
            num_points = n;
            points = new Point[num_points];
        }
        virtual ~Shape() {
            delete[] points;
        }
        void changePoint(size_t index, const Point& point);
        size_t getNumPoints() const{
            return num_points;
        }
        const Point& getPoint(size_t index) const{
            return points[index];
        }
        virtual double getArea() const = 0;
        virtual double getPerimeter() const = 0;
        virtual bool isInFigure(const Point& point) const = 0;
};

void Shape::changePoint(size_t index, const Point& point){
    if(index >= num_points) return;
    points[index] = point;
    return;
}

class Triangle : public Shape {
    public:
        ~Triangle(){}
        Triangle(const Point& p1, const Point& p2, const Point& p3);
        double getPerimeter() const;
        double getArea() const;
};

Triangle::Triangle(const Point& p1, const Point& p2, const Point& p3) : Shape(3) {
    changePoint(1, p1);
    changePoint(2, p2);
    changePoint(3, p3);
}

double Triangle::getPerimeter() const {
    return getPoint(1).getLength(getPoint(2)) + getPoint(2).getLength(getPoint(3)) + getPoint(3).getLength(getPoint(1)); 
}

double Triangle::getArea() const {
    double halfArea = getPerimeter()/2;
    return sqrt(
        halfArea
        *(halfArea - getPoint(1).getLength(getPoint(2)))
        *(halfArea - getPoint(2).getLength(getPoint(3)))
        *(halfArea - getPoint(3).getLength(getPoint(1)))
    );
}

class Rectangle : public Shape {
    public:
        ~Rectangle(){}
        Rectangle(const Point& p1, const Point& p2);
        double getPerimeter() const;
        double getArea() const;
};

Rectangle::Rectangle(const Point& p1, const Point& p2) : Shape(2) {
    changePoint(1, p1);
    changePoint(2, p2);
}

double Rectangle::getPerimeter() const {
    return getPoint(1).getLength(getPoint(2))*M_PI; 
}

double Rectangle::getArea() const {
    return 2*getPerimeter();
}


class Circle : public Shape {
    public:
        Circle(const Point& p1, const Point& p2);
        ~Circle() {}
        double getPerimeter() const;
        double getArea() const;
};

Circle::Circle(const Point& p1, const Point& p2) : Shape(2) {
    changePoint(1, p1);
    changePoint(2, p2);
}

double Circle::getPerimeter() const {
    return getPoint(1).getLength(getPoint(2))*M_PI; 
}

double Circle::getArea() const {
    return 2*getPerimeter();
}


int main(){

}