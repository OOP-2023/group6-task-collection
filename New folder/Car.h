#pragma once
#include "FuelTank.h"
#include "accumulator.h"
#include "Tyres.h"
#include "engine.h"
#include "carParts.h"

class Car
{
	FuelTank reservoir;
	Engine _engine;
	Tyres _tyres[4];
	Accumulator _accum;
	unsigned distance;
	unsigned weight;
public:

};