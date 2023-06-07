#include "TextBox.hpp"

const char* TextBox::get_text()
{
	return this->text.c_str();
}

void TextBox::print() const
{
	std::cout << "Text: " << text << std::endl;
}

void TextBox::show_dialog()
{
	std::cout << "Enter text: ";
	std::cin >> text;
}
