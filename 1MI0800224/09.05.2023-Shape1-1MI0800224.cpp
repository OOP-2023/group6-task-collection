#include <iostream>
#include <cmath>

struct Point{
    double x,y;
    void modifyDirection(double x_new, double y_new){
        x=x_new;
        y=y_new;
    }
};

class Shape{
protected:
    Point* points;//array with points
    unsigned count_points;
public:
    //pure virtual methods
    virtual double findArea() =0;
    virtual double findPerimeter()=0;
    virtual bool isPointInShape()=0;
    virtual ~Shape()=default;
};
/*
class five : public Shape {
    five() : Shape(5) {
        this->points[0] = ...;
    }
}
*/

class Circle: public Shape {
public:
    //constructor
    Circle(Point* punkte, unsigned counter){
        this->points=new Point[sizeof(punkte)];
        this->count_points=counter;
    }
    //getter
    unsigned getCount_points()const{
        return count_points;
    }

    double findArea() override {
        double radius=sqrt((points[0].x-points[1].x)*(points[0].x-points[1].x)+(points[0].y-points[1].y)*(points[0].y-points[1].y));
        return 3.1415296*radius*radius;
    }
    double findPerimeter() override {
        double radius=sqrt((points[0].x-points[1].x)*(points[0].x-points[1].x)+(points[0].y-points[1].y)*(points[0].y-points[1].y));
        return 2*3.1415296*radius;
    }
    bool isPointInShape(Point current, const Circle& figure) const{
        double radius=sqrt((points[0].x-points[1].x)*(points[0].x-points[1].x)+(points[0].y-points[1].y)*(points[0].y-points[1].y));
        double distance = sqrt((current.x-points[0].x)*(current.x-points[1].x)+(current.y-points[1].y)*(current.y-points[1].y));
        return radius-distance>=0;
    }

};

class Triangle: public Shape{
private:
    Point* points;
    unsigned count_points=3;
public:

    //constructor
    Triangle(Point* punkte, unsigned counter){
        this->points=new Point[sizeof(punkte)];
        this->count_points=counter;
    }
    //getter
    unsigned getCount_points()const{
        return count_points;
    }

    double findArea(const Point* points, unsigned counter){
        //Heron S=sqrt(p*(p-a)*(p-b)*(p-c));
        //Find AB=(x0, y0)(x1, y1)
        double AB=sqrt((points[0].x-points[1].x)*(points[0].x-points[1].x)+(points[0].y-points[1].y)*(points[0].y-points[1].y));
        double AC=sqrt((points[0].x-points[2].x)*(points[0].x-points[2].x)+(points[0].y-points[2].y)*(points[0].y-points[2].y));
        double BC=sqrt((points[2].x-points[1].x)*(points[2].x-points[1].x)+(points[2].y-points[1].y)*(points[2].y-points[1].y));
        double p=(AB+AC+BC)/2;
        return sqrt(p*(p-AB)*(p-AC)*(p-BC));
    }
    double findPerimeter(const Point* points, unsigned counter){
        double AB=sqrt((points[0].x-points[1].x)*(points[0].x-points[1].x)+(points[0].y-points[1].y)*(points[0].y-points[1].y));
        double AC=sqrt((points[0].x-points[2].x)*(points[0].x-points[2].x)+(points[0].y-points[2].y)*(points[0].y-points[2].y));
        double BC=sqrt((points[2].x-points[1].x)*(points[2].x-points[1].x)+(points[2].y-points[1].y)*(points[2].y-points[1].y));
        return (AB+AC+BC);
    }
    bool isPointInShape(Point current, const Triangle& figure) const;

};

class Rectangle: public Shape{
private:
    Point* points;
    unsigned count_points=3;
public:

    //constructor
    Rectangle(Point* punkte, unsigned counter){
        this->points=new Point[sizeof(punkte)];
        this->count_points=counter;
    }
    //getter
    unsigned getCount_points()const{
        return count_points;
    }

    void findArea(const Point* points, unsigned counter);
    void findPerimeter(const Point* points, unsigned counter);
    bool isPointInShape(Point current, const Rectangle& figure) const;

};

int main(){
}
