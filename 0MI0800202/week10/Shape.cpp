//
// Created by swordypepe on 5/9/23.
//

#include "Shape.h"
#include <cmath>


Triangle::Triangle(Shape::Point A, Shape::Point B, Shape::Point C)
{
    points = new Point[3];
    points[0] = A;
    points[1] = B;
    points[2] = C;
    double AB = B - A, BC = C - B, AC = C - A;
    perimeter = AB + BC + AC;
    double halfper = perimeter/2;
    area = (halfper) * (halfper - AB) * (halfper - BC) * (halfper - AC);
}

double Triangle::getArea()
{
    return area;
}

double Triangle::getPer()
{
    return perimeter;
}

double operator-(const Shape::Point &lhs, const Shape::Point &rhs)
{
    Shape::Point result;
    result.x = lhs.x - rhs.x;
    result.y = lhs.y - rhs.y;
    return sqrt(result.x * result.x + result.y* result.y);
}

void Shape::Point::setPoint(int _x, int _y)
{
    x = _x;
    y = _y;
}

Circle::Circle(Shape::Point A, Shape::Point B)
{
    double AB = B - A;
    radius = AB;
    perimeter
}
