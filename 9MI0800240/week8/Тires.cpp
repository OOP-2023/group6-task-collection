#include "Тires.h"


std::ostream& operator<<(std::ostream& os, const Tires& arg)
{
	
	os << static_cast<const CarPart&>(arg) << arg._width << arg._profile << arg._diameterInInches;

	return os;
}

Tires::Tires() : CarPart(), _width(0), _profile(0), _diameterInInches(0)
{}

Tires::Tires(const char* identifier, const char* manufacturerName, const char* description,
	const size_t width, const size_t profile, const size_t diameterInInches) : CarPart::CarPart(identifier, manufacturerName, description)
{
	this->_width = width;
	this->_profile = profile;
	this->_diameterInInches = diameterInInches;
}
