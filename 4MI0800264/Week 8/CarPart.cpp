#include <iostream>
#include <cstring>
#include "CarPart.h"


void CarPart::freeId()
{
	if (id != nullptr)
		delete[] id;
}
void CarPart::freeManufacturerName()
{
	if (manufacturerName != nullptr)
		delete[] manufacturerName;

}
void CarPart::freeDescription()
{
	if (description != nullptr)
		delete[] description;
}

void CarPart::free()
{
	freeId();
	freeManufacturerName();
	freeDescription();
	
	id = nullptr;
	manufacturerName = nullptr;
	description = nullptr;
}

char* CarPart::getId() const
{
	return id;
}
void CarPart::setId(const char* inputId)
{
	freeId();

	id = new char[strlen(inputId) + 1];
	strcpy(id, inputId);
}

char* CarPart::getManufacturerName() const
{
	return manufacturerName;
}
void CarPart::setManufacturerName(const char* inputManufacturerName)
{
	freeManufacturerName();

	manufacturerName = new char[strlen(inputManufacturerName) + 1];
	strcpy(manufacturerName, inputManufacturerName);
}

char* CarPart::getDescription() const
{
	return description;
}
void CarPart::setDescription(const char* inputDescription)
{
	freeDescription();

	description = new char[strlen(inputDescription) + 1];
	strcpy(description, inputDescription);
}

CarPart::CarPart(const char* inputId = "", const char* inputManufacturerName = "", const char* inputDescription = "")
{
	setId(inputId);
	setManufacturerName(inputManufacturerName);
	setDescription(inputDescription);
}