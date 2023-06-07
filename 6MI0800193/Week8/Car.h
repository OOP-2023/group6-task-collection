#ifndef _CAR_HPP
#define _CAR_HPP
#include "CarPart.hpp"
#include "Tire.hpp"
#include "Battery.hpp"
#include "Engine.hpp"
#include "FuelTank.hpp"
class Car
{
private:

public:
	FuelTank tank;
	Tire tires[4];
	Engine engine;
	Battery battery;
	unsigned mileage;
	unsigned weight;
};

#endif // !_CAR_HPP
