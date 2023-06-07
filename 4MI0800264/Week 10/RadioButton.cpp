#include "RadioButton.h"



RadioButton& RadioButton::operator= (const RadioButton& other)
{
	if(this !=&other)
	{
		strcpy(text, other.text);
		isChosen = other.isChosen;

		setXAndY(other.getX(), other.getY());
	}

	return *this;
}

void RadioButton::showDialog()
{
	std::cout << "Enter Name >";
	std::cin.ignore();
	std::cin >> text;

	int tempChosen;

	std::cout << "Enter 1 if the button is pressed and 0 if the button is not pressed >";
	std::cin >> tempChosen;

	isChosen = (tempChosen == 0) ? false : true;
}

void RadioButton::flip()
{
	isChosen = (isChosen) ? false : true;
}

bool RadioButton::isOn() const
{
	return isChosen;
}
