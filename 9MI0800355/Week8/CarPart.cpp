// Exercise1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "CarPart.h"
#include <iostream>
#include <cstring>

void CarPart::copy(const CarPart& other) {
	copy(other.id, this->id);
	copy(other.description, this->description);
	copy(other.manufacturerName, this->manufacturerName);
}

void CarPart::copy(const char* source, char*& target) {
	target = new char[strlen(source) + 1];
	strcpy(target, source);
}

void CarPart::free() {
	delete[] id;
	delete[] description;
	delete[] manufacturerName;
}

CarPart::CarPart(const char* id, const char* manufacturerName, const char* description) {
	copy(id, this->id);
	copy(description, this->description);
	copy(manufacturerName, this->manufacturerName);
}

CarPart::CarPart(const CarPart& other) {
	copy(other);
}

const CarPart& CarPart::operator=(const CarPart& other) {
	if (this != &other) {
		free();
		copy(other);
	}

	return *this;
}

CarPart::~CarPart() {
	free();
}

const char* CarPart::getManufacturerName() const {
	return manufacturerName;
}

const char* CarPart::getDescription() const {
	return description;
}

const char* CarPart::getId() const {
	return id;
}

int main()
{

}

