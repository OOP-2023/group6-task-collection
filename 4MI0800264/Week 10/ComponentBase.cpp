#include <iostream>
#include <cstring>
#include "ComponentBase.h"



void ComponentBase::setXAndY(float inputX, float inputY)
{
	x = inputX;
	y = inputY;
}

float ComponentBase::getX() const
{
	return x;
}

float ComponentBase::getY() const
{
	return y;
}





