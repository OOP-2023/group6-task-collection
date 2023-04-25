#pragma once

class Wheel
{
	int width;
	int profile;
	int diameter;

public:
	Wheel(int inputWidth, int inputProfile, int inputDiameter);

	int getWidth() const;
	void setWidth(int inputWidth);

	int getProfile() const;
	void setProfile(int inputProfile);

	int getDiameter() const;
	void setDiameter(int inputDiameter);
};