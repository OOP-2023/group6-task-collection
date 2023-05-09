#include <iostream>
#include "Circle.h"
#include "Rect.h"
#include "Triangle.h"
#include "PointCollection.h"
using namespace std;

int main()
{
    PointCollection col;

    col.add_circle({ 0,0 }, { 2,2 });
    col.add_rectangle({ 0,0 }, { 2,2 }, { 2,4 }, { 0,4 });
    col.add_triangle({ 0, 0 }, { 5,0 }, { 2,5 });

    col.print_areas(cout);
    cout << endl;
    col.print_perimeters(cout);
}
