#include "TextBox.h"



TextBox& TextBox::operator= (const TextBox& other)
{
	if(this != &other)
	{
		delete[] text;

		text = new char[strlen(other.text) + 1];
		strcpy(text, other.text);

		setXAndY(other.getX(), other.getY());
	}

	return *this;
}

void TextBox::showDialog()
{
	char buff[1024];
	std::cout << "Enter Name >";
	std::cin.ignore();
	std::cin >> buff;

	if (text != nullptr)
	{
		delete[] text;
	}

	text = new char[strlen(buff) + 1];
	strcpy(text, buff);
}

TextBox::~TextBox()
{
	if (text != nullptr)
		delete[] text;

}


