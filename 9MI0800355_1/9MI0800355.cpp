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


#pragma once

#include <iostream>

class CarPart {
private:
	char* id;
	char* description;
	char* manufacturerName;

	void copy(const CarPart& other);

	void copy(const char* source, char*& target);

	void free();

public:
	CarPart(const char* id, const char* manufacturerName, const char* description);

	CarPart(const CarPart& other);

	const CarPart& operator=(const CarPart& other);

	~CarPart();

	const char* getManufacturerName() const;

	const char* getDescription() const;

	const char* getId() const;
};




#include "CarPart.h"
#include <iostream>

class Tyre {
private:
	const int minWidth = 155;
	const int maxWidth = 365;
  const int minProfil = 30;
  const int maxProfil = 80;
  const minDiamInInch = 13;
  const maxDiamInInch = 21;
};




