#include "Label.h"


Label& Label::operator= (const Label& other)
{
	if(this != &other)
	{
		strcpy(array, other.array);

		setXAndY(other.getX(), other.getY());
	}

	return *this;
}

void Label::showDialog()
{
	float tempX, tempY;

	std::cout << "Enter Coordinates x & y >";
	std::cin >> tempX >> tempY;

	setXAndY(tempX, tempY);

	std::cout << "Enter Label >";
	std::cin.ignore();
	std::cin >> array;
}