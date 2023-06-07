#include "RadioButton.hpp"
#include <iostream>
void RadioButton::show_dialog()
{
	std::cout << "Enter name: ";
	std::cin.getline(this->text, 16);

	std::cout << "Is button on? - " << (checked ? "Yes" : "No") << std::endl;
}

void RadioButton::print() const
{
	std::cout << "Name: " << text << std::endl;
	std::cout << "Is button on? - " << (checked ? "Yes" : "No") << std::endl;
}

void RadioButton::flip()
{
	this->checked = !this->checked;
}

bool RadioButton::is_on() const
{
	return this->checked;
}
