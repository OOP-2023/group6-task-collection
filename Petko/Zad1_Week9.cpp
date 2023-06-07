// Zad1_Week8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
class CarPart {
	public:
	char* identificator;
	char* manufacturer;
	char* description;
public:
	CarPart();
	~CarPart();
	CarPart(CarPart const& other);
	CarPart& operator=(CarPart const& other);
	CarPart(CarPart&& other);
	CarPart& operator=(CarPart&& other);
};
CarPart::CarPart() {
	identificator=new char[1];
	identificator[0] = '\0';
	manufacturer = new char[1];
	manufacturer[0] = '\0';
	description = new char[1];
	description[0] = '\0';
}
CarPart::~CarPart() {
	delete[] identificator;
	delete[] manufacturer;
	delete[] description;
}
CarPart::CarPart(CarPart const& other) {
	identificator = new char[strlen(other.identificator) + 1];
	strcpy(identificator, other.identificator);
	manufacturer = new char[strlen(other.manufacturer) + 1];
	strcpy(manufacturer, other.manufacturer);
	description = new char[strlen(other.description) + 1];
	strcpy(description, other.description);
}
CarPart& CarPart::operator=(CarPart const& other) {
	if (this != &other)
	{
		delete[] identificator;
		identificator = new char[strlen(other.identificator) + 1];
		strcpy(identificator, other.identificator);
		delete[] manufacturer;
		manufacturer = new char[strlen(other.manufacturer) + 1];
		strcpy(manufacturer, other.manufacturer);
		delete[] description;
		description = new char[strlen(other.description) + 1];
		strcpy(description, other.description);
	}
	return *this;
}
CarPart::CarPart(CarPart&& other) {
	identificator = other.identificator;
	other.identificator = nullptr;
	manufacturer = other.manufacturer;
	other.manufacturer = nullptr;
	description = other.description;
	other.description = nullptr;
}
CarPart& CarPart::operator=(CarPart&& other) {
	if (this != &other) {
		delete[]identificator;
		identificator = other.identificator;
		other.identificator = nullptr;
		delete[]manufacturer;
		manufacturer = other.manufacturer;
		other.manufacturer = nullptr;
		delete[]description;
		description = other.description;
		other.description = nullptr;
	}
	return *this;
}
class Engine :public CarPart {
public:
	unsigned horsePower;
	
};
class Tires :public CarPart {
public:
	unsigned width;
    unsigned profile;
	unsigned diameter;
};
class Battery :public CarPart {
public:
	unsigned capacity;
	char* batteryId;
};
int main()
{
   
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
