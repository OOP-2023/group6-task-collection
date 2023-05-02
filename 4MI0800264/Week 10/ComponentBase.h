#pragma once

#include <iostream>
#include <cstring>
#pragma warning(disable:4996)

class ComponentBase
{
	float x;
	float y;

public:
	virtual void showDialog() = 0;
	virtual void move(float dx, float dy) = 0;

	void setXAndY(float inputX, float inputY);

	float getX() const;

	float getY() const;

};
