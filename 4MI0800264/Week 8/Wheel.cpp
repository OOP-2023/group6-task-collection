#include <iostream>
#include "Wheel.h"

int Wheel::getWidth() const
{
	return width;
}
void Wheel::setWidth(int inputWidth)
{
	if (inputWidth < 155 || inputWidth > 365)
		throw std::runtime_error("You have entered incorrect width! Keep it between 155 and 365!");

	width = inputWidth;

}

int Wheel::getProfile() const
{
	return profile;
}
void Wheel::setProfile(int inputProfile)
{
	if (inputProfile < 30 || inputProfile > 80)
		throw std::runtime_error("You have entered incorrect profile! Keep it between 30 and 80!");

	profile = inputProfile;
}

int Wheel::getDiameter() const
{
	return diameter;
}
void Wheel::setDiameter(int inputDiameter)
{
	if (inputDiameter < 13 || inputDiameter > 21)
		throw std::runtime_error("You have entered incorrect diameter! Keep it between 13 and 21!");

	diameter = inputDiameter;
}

Wheel::Wheel(int inputWidth, int inputProfile, int inputDiameter)
{
	setWidth(inputWidth);
	setProfile(inputProfile);
	setDiameter(inputDiameter);
}

