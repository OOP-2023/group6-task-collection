#include "Label.hpp"
#include <iostream>

void Label::print() const
{
	std::cout << "Coords: (x,y) (" << x << ", " << y << ")" << std::endl;
	std::cout << content << std::endl;
}

void Label::show_dialog()
{
	std::cout << "Enter label x coord: ";
	std::cin >> this->x;

	std::cout << "Enter label y coord: ";
	std::cin >> this->y;

	std::cout << "Enter label content: ";
	std::cin.ignore();
	std::cin.getline(this->content, 16);
}
