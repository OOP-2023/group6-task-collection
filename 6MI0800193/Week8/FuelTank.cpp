#include "FuelTank.hpp"

FuelTank::FuelTank()
{
	this->capacity = 0;
	this->fuel_atm = 0;
}

FuelTank::FuelTank(double cap)
{
	this->capacity = cap;
	this->fuel_atm = cap;
}

void FuelTank::to_use(double used)
{
	if (used > this->capacity)
		throw insufficient_fuel_error("Not enough fuel");
}

void FuelTank::to_fill(double filled)
{
	if (this->fuel_atm + filled > this->capacity)
		this->fuel_atm = this->capacity;
	else
		this->fuel_atm += filled;
}
