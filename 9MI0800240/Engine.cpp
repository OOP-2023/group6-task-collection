#include "Engine.h"

Engine::Engine(const char* identifier, const char* manufacturerName, const char* description, int horsepower) :
	CarPart::CarPart(identifier, manufacturerName, description)
{
	this->_horsepower = horsepower;
}

std::ostream& operator<<(std::ostream& os, const Engine& engine)
{
	os << static_cast<const CarPart&>(engine) << engine._horsepower;

	return os;
}
