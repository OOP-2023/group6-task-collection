#include <iostream>
using namespace std;

class Shape {
private:
    struct point {
        int x=0;
        int y=0;
    };
    point* points;
    size_t pointNumber;
    void free();
    void copy(const Shape& other);
public:
    Shape(point* points, size_t pointNumber);
    Shape(Shape& other);
    Shape& operator=(Shape& other);
    virtual ~Shape();

    double getDist(point point1, point point2);
    void changePoint(size_t position,int x, int y);
    virtual double area(const Shape& other);
    virtual int perimeter(const Shape& other);
    virtual bool isInArea(point p);
};
void Shape::free() {
    delete[] points;
}
void Shape::copy(const Shape& other) {
    
    pointNumber = other.pointNumber;
    points = new point[pointNumber];
    for (int i = 0; i < pointNumber; ++i) {
        points[i] = other.points[i];
    }
}
Shape::Shape(point* points, size_t pointNumber) {
    points = new point[pointNumber];
}
Shape::Shape(Shape& other) {
    copy(other);
}
Shape& Shape::operator=(Shape& other) {
    if (this != &other) {
        free();
        copy(other);
    }
    return *this;
}
Shape::~Shape() {
    free();
}
double Shape::getDist(point point1, point point2) {
    return sqrt((point2.x - point1.x) * (point2.x - point1.x) + (point2.y - point1.y) * (point2.y - point1.y));
}
void Shape::changePoint(size_t position,int _x, int _y) {
    points[position].x = _x;
    points[position].y = _y;
}
double Shape::area(const Shape& other) {

}
int Shape::perimeter(const Shape& other) {
    int per = 0;
    for (int i = 0; i < other.pointNumber-1; ++i) {
        for (int j = 0; j < other.pointNumber; ++j) {
            per += getDist(other.points[i],other.points[j]);
        }
    }
    return per;
}
bool Shape::isInArea(point p) {
    
}
class Circle : public Shape {
public:
    virtual double area(const Shape& other)override;
    virtual int perimeter(const Shape& other)override;
    virtual bool isInArea(point p)override;
};
double Circle::area(const Shape& other){

}
int Circle::perimeter(const Shape& other){

}
bool Circle::isInArea(point p){

}
class Triangle : public Shape {
public:
    virtual double area(const Shape& other)override;
    virtual int perimeter(const Shape& other)override;
    virtual bool isInArea(point p)override;
};
double Triangle::area(const Shape& other) {

}
int Triangle::perimeter(const Shape& other) {

}
bool Triangle::isInArea(point p) {

}
class Rectangle : public Shape {
public:
    virtual double area(const Shape& other)override;
    virtual int perimeter(const Shape& other)override;
    virtual bool isInArea(point p)override;
};
double Rectangle::area(const Shape& other) {

}
int Rectangle::perimeter(const Shape& other) {

}
bool Rectangle::isInArea(point p) {

}
int main()
{
    void printAreas(const Shape* const*, size_t);
    void printPerimeters(const Shape* const*, size_t);
    void freeCollection(Shape**, size_t);
}
