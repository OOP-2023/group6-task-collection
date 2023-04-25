#include "FuelTank.h"
#include <iostream>

FuelTank::FuelTank(unsigned _capacity)
{
	capacity = _capacity;
	fullness = _capacity;
}

void FuelTank::use(double to_use)
{
	if (to_use - fullness > 0.00001)
		throw std::logic_error("insufficient_fuel_error");
	fullness -= to_use;
}

void FuelTank::fill(double to_use)
{
	if (fullness + to_use - capacity>=0.00001)
		fullness = capacity;
	fullness += to_use;
}

const FuelTank& get_fuel_tank()
{

}