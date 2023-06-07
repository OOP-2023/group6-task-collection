#pragma once
#include "CarPart.h"
class Accumulator : private CarPart
{
	unsigned capacity; //in Ah
	char* batteryId;

	void free();

public:
	Accumulator(unsigned = 0,
		const char* = "",
		const char* inputId = "",
		const char* inputManufacturerName = "",
		const char* inputDescription = "");

	~Accumulator();

	unsigned getCapacity() const;
	void setCapacity(unsigned inputCapacity);

	char* getBatteryId() const;
	void setBatteryId(const char* inputBatteryId);
};