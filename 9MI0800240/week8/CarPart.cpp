#include "CarPart.h"
#include<cstring>
#pragma warning(disable:4996)
std::ostream& operator<<(std::ostream& out, const CarPart& date)
{
	if (date._description == nullptr || date._manufacturerName || date._description)
		return;
	out << date._identifier << ' ' << date._manufacturerName << ' ' << date._description;
	return out;
}

std::istream& operator>>(std::istream& in, CarPart& date)
{
	in >> date._identifier;
	in.ignore(1, ' ');
	in >> date._manufacturerName;
	in.ignore(1, ' ');
	in >> date._description;

	return in;
}

void copyDynamicCharArray(char*& destination, const char* source)
{
	destination = new char[strlen(source) + 1];
	strcpy(destination, source);
}


void CarPart::copyFrom(const CarPart& other)
{
	copyDynamicCharArray(this->_identifier, other._identifier);
	copyDynamicCharArray(this->_manufacturerName, other._manufacturerName);
	copyDynamicCharArray(this->_description, other._description);
}

void CarPart::free()
{
	delete[] _identifier;
	delete[] _manufacturerName;
	delete[] _description;
}

CarPart::CarPart() : 
	_identifier(nullptr),
_manufacturerName(nullptr), _description(nullptr)
{}

CarPart::CarPart(const char* identifier, const char* manufacturerName, const char* description)
{

	copyDynamicCharArray(this->_identifier, identifier);
	copyDynamicCharArray(this->_manufacturerName, manufacturerName);
	copyDynamicCharArray(this->_description, description);
}

CarPart::CarPart(const CarPart& other)
{
	copyFrom(other);
}

CarPart& CarPart::operator=(const CarPart& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

CarPart::~CarPart()
{
	free();
}
