#include "Tire.hpp"
#include <stdexcept>
Tire::Tire() : CarPart()
{
	this->width = 155;
	this->profile = 30;
	this->diameter = 13;
}

Tire::Tire(int w, int p, int d, const char* id, const char* man_name, const char* desc) : CarPart(id, man_name, desc)
{
	if (!validate(w, 155, 365) || !validate(p, 30, 80) || !validate(d, 13, 21))
	{
		throw std::invalid_argument("Invalid argument!");
	}

	this->width = w;
	this->profile = p;
	this->diameter = d;
}

int Tire::get_width() const
{
	return this->width;
}

int Tire::get_profile() const
{
	return this->profile;
}

int Tire::get_diameter() const
{
	return this->diameter;
}

void Tire::set_width(int w)
{
	if (!validate(w, 155, 365))
	{
		throw std::invalid_argument("Invalid argument!");
	}
	this->width = w;
}

void Tire::set_profile(int p)
{
	if (!validate(p, 30, 80))
	{
		throw std::invalid_argument("Invalid argument!");
	}
	this->profile = p;
}

void Tire::set_diameter(int d)
{
	if (!validate(d, 13, 21))
	{
		throw std::invalid_argument("Invalid argument!");
	}
	this->diameter = d;
}

bool Tire::validate(int value, int min, int max)
{
	return value >= min && value <= max;
}

std::ostream& operator<< (std::ostream& out, const Tire& tire)
{
	out << (CarPart&)tire;
	out << " - " << tire.width << '/' << tire.profile << 'R' << tire.diameter;
	return out;
}
