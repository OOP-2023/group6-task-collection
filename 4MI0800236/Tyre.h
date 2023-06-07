#pragma once

#include "CarPart.h"
#include <iostream>

class Tyre {
private:
	const int minWidth = 155;
	const int maxWidth = 365;

	const int minProfile = 30;
	const int maxProfile = 80;

	const int minDiameter = 13;
	const int maxDiameter = 21;

	int width;
	int profile;
	int diameter;

public:
	Tyre(const char* id, const char* manufacturer, const char* description)
};
