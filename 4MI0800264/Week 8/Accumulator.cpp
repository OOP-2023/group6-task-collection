#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
#include "Accumulator.h"
#include "CarPart.h"

unsigned Accumulator::getCapacity() const
{
	return capacity;
}
void Accumulator::setCapacity(unsigned inputCapacity)
{
	capacity = inputCapacity;
}

char* Accumulator::getBatteryId() const
{
	return batteryId;
}
void Accumulator::setBatteryId(const char* inputBatteryId)
{
	free();

	batteryId = new char[strlen(inputBatteryId) + 1];
	strcpy(batteryId, inputBatteryId);

}

void Accumulator::free()
{
	if (batteryId != nullptr)
		delete[] batteryId;

	batteryId = nullptr;
}

Accumulator::Accumulator(unsigned inputCapacity = 0,
	const char* inputBatteryId = "",
	const char* inputId = "",
	const char* inputManufacturerName = "",
	const char* inputDescription = "") : CarPart(inputId, inputManufacturerName, inputDescription)
{
	setCapacity(inputCapacity);
	setBatteryId(inputBatteryId);
}

Accumulator::~Accumulator()
{
	free();
}