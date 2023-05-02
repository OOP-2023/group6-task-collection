#include <iostream>
#include <fstream>
#include <sstream>
#include "Component.hpp"
#pragma warning (disable : 4996)

// class ComponentBase
void ComponentBase::move(double dx, double dy)
{
	x += dx;
	y += dy;
}
//-----------------------

// class Label
void Label::showDialog()
{
	std::cout << "Write two coordinates for the component" << std::endl;
	std::cin >> x >> y;
	std::cout << "Write name for the label (max 16 symbols)" << std::endl;
	char buff[1024];
	do
	{
		std::cin >> buff;
	} while (strlen(buff) > 16);
	
	strcpy(name, buff);
}

ComponentBase* Label::clone()
{
	return new Label(*this);
}
//-----------------------

//class RadioButton
void RadioButton::showDialog() 
{
	std::cout << "Write name for the label (max 16 symbols)" << std::endl;
	char buff[1024];
	do
	{
		std::cin >> buff;
	} while (strlen(buff) > 16);
	strcpy(name, buff);

	std::cout << "Is the button selected or not t/f" << std::endl;
	std::cin >> isSelect;
}

void RadioButton::flip()
{
	isSelect = !isSelect;
}

bool RadioButton::isOn()
{
	return isSelect;
}

ComponentBase* RadioButton::clone()
{
	return new RadioButton(*this);
}
//-----------------------


//class TextBox
void TextBox::showDialog()
{
	char type[5];
	std::cout << "cin/text" << std::endl;
	std::cin.getline(type, 5, ' ');

	if (strcmp(type, "cin") == 0)
	{
		std::cin >> context;
	}
	else
	{
		std::cout << "Write down the filePath" << std::endl;
		char fileName[1024];
		std::cin.getline(fileName, 1024, ' ');

		std::ifstream file(fileName, std::ios::out);
		if (!file.is_open())
		{
			throw std::exception("file did not open!");
			return;
		}

		std::stringstream buffer;
		buffer << file.rdbuf();
		context = buffer.str();
	}
}

ComponentBase* TextBox::clone()
{
	return new TextBox(*this);
}
//-----------------------

//class Collection
void Collection::addLabel()
{
	ComponentBase* component = new Label;
	//component->showDialog();
	collection.push_back(component);
}

void Collection::addRadioButton()
{
	ComponentBase* component = new RadioButton;
	//component->showDialog();
	collection.push_back(component);
}

void Collection::addTextBox()
{
	ComponentBase* component = new TextBox;
	//component->showDialog();
	collection.push_back(component);
}
void Collection::free()
{
	for (size_t i = 0; i < collection.size(); i++)
		delete collection[i];
}

void Collection::copy(const Collection& other)
{
	for (size_t i = 0; i < other.collection.size(); i++)
		collection[i] = other.collection[i]->clone();
}

Collection::~Collection()
{
	free();
}
Collection::Collection(const Collection& other)
{
	copy(other);
}
Collection& Collection::operator=(const Collection& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}
	return *this;
}

//-----------------------
int main()
{
	Collection ck;
}
