#include <iostream>
using namespace std;

class Shape {
protected:
    struct Point {
        double _x;
        double _y;

        void copy(const Point& pt)
        {
            _x = pt._x;
            _y = pt._y;
        }
    };


    double getDistance(Point p1, Point p2)
    {
        return sqrt((p2._x - p1._x) * (p2._x - p1._x) + (p2._y - p1._y) * (p2._y - p1._y));
    }
    Point* point;
    int count;
private:


    void copyFrom(const Shape& shape)
    {
        this->count=shape.count;
        for (size_t i = 0; i < count; i++)
        {
            this->point[i] = shape.point[i];
        }
    }

    void free()
    {
        delete[] point;
    }

public:
    Shape(int count)
    {
        Point* shape = new Point[count];
    }


    Shape()
    {
        point = nullptr;
        count = 0;
    }

    Shape(const Shape& current)
    {
        copyFrom(current);
    }

    Shape& operator=(const Shape& other)
    {
        if (this != &other)
        {
            free();
            copyFrom(other);
        }
        return *this;
    }

    virtual ~Shape()
    {
        free();
    }

    void changePoint(double x, double y, size_t pos)
    {
        point[pos]._x = x;
        point[pos]._y = y;
    }

    virtual double getS() = 0;

    virtual double getPerimeter() = 0;

    virtual bool isContain(Point p1) = 0;
   
};

const double Pi = 3.14;

class Circle : Shape{
    Point center;
    double r;
public:
    Circle() : Shape(1) {
    }

    double getS() override
    {
        return Pi * r * r;
    }

    double getPerimeter() override
    {
        return 2* Pi* r;
    }
};

class Triangle : public Shape {
public:
    Triangle() : Shape(3) {
    }

    double getPerimeter()  override
    {
        double perimeter = 0;
        for (size_t i = 0; i < 2; i++)
        {
            perimeter +=  getDistance(point[i], point[i + 1]);
        }
        return perimeter;
    }
    double getS() override
    {
        double halfPer = getPerimeter() / 2.0;
        double Area = halfPer;
        for (size_t i = 0; i < 2; i++)
        {
            Area *= halfPer - getDistance(point[i], point[i + 1]);
        }
        Area = sqrt(Area);
    }
};

class Rectangle :public Shape{
public:
    Rectangle() : Shape(2) {
    }
    double getPerimeter()  override
    {

    }
};


int main()
{
    
}


