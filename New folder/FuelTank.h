#pragma once

class FuelTank  
{
	unsigned capacity;
	unsigned fullness;
public:
	FuelTank(unsigned _capacity);

	void use(double to_use);
	void fill(double to_use);
	const FuelTank& get_fuel_tank();
};
