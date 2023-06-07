#ifndef _FUEL_TANK_HPP
#define _FUEL_TANK_HPP
#include<stdexcept>
class FuelTank
{
private:
	double capacity;
	double fuel_atm;
public:


	FuelTank();
	FuelTank(double cap);

	void to_use(double used);
	void to_fill(double filled);
};

class insufficient_fuel_error : public std::logic_error {
public:
	insufficient_fuel_error(const char* data) : std::logic_error(data)
	{

	}
};

#endif // !_FUEL_TANK_HPP
