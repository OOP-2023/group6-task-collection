#ifndef _SHAPE_HPP
#define _SHAPE_HPP

class Shape {
protected:
	struct Point {
		int x;
		int y;
	};
	Point* points;
	size_t index;
	size_t capacity;
public:
	Shape(size_t);
	~Shape();
	void setPoint(int, int);
	virtual double getArea() = 0;
	virtual double getPerm() = 0;
	virtual void setSides() = 0;
};

class Circle : public Shape {
private:
	double radius = 0;
	void setSides() override;
public:
	Circle(size_t);
	~Circle() = default;
	double getArea() override;
	double getPerm() override;

};

class Rectagnle : public Shape {
private:
	double bigSide = 0;
	double smallSide = 0;
	void setSides() override;
public:
	Rectagnle(size_t);
	~Rectagnle() = default;
	double getArea() override;
	double getPerm() override;
};

class Triangle : public Shape {
private:
	double firstSide = 0;
	double secondSide = 0;
	double thirdSide = 0;
	void setSides() override;
public:
	Triangle(size_t);
	~Triangle() = default;
	double getArea() override;
	double getPerm() override;
};
#endif // !_SHAPE_HPP
