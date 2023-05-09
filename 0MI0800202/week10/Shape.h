#ifndef WEEK10_SHAPE_H
#define WEEK10_SHAPE_H


class Shape
{
public:
    struct Point
    {
        int x;
        int y;
        friend double operator-(const Point& lhs, const Point& rhs);
        void setPoint(int x, int y);
    };

    virtual double getArea() = 0;
    virtual double getPer() = 0;
protected:
    virtual ~Shape() = 0;
    Point* points;
    int capacity;
};

class Triangle : public Shape
{
private:
    double area;
    double perimeter;
public:
    Triangle(Point A, Point B, Point C);
    double getArea() override;
    double getPer() override;
};
class Circle : public Shape
{
private:
    double radius;
    double area;
    double perimeter;
public:
    Circle(Point A, Point B);
    void setArea();
};
class Rectangle
{

};



#endif //WEEK10_SHAPE_H
