#define _CRT_SECURE_NO_WARNINGS
#include "Battery.hpp"

Battery::Battery()
{
	this->capacity = 0;
	this->battery_id = new char[1];
	this->battery_id[0] = '\0';
}

Battery::Battery(int cap, const char* batt_id, const char* id, const char* man_name, const char* desc) : CarPart(id, man_name, desc)
{
	this->capacity = cap;
	this->battery_id = new char[strlen(batt_id) + 1];
	strcpy(this->battery_id, batt_id);
}

Battery::~Battery()
{
	delete[] battery_id;
}

Battery::Battery(const Battery& bat) : CarPart(bat)
{
	this->capacity = bat.capacity;
	this->battery_id = new char[strlen(bat.battery_id) + 1];
	strcpy(this->battery_id, bat.battery_id);
}

Battery& Battery::operator=(const Battery& rhs)
{
	if (this != &rhs)
	{
		CarPart::operator=(rhs);
		delete[] this->battery_id;

		this->capacity = rhs.capacity;
		this->battery_id = new char[strlen(rhs.battery_id) + 1];

		strcpy(this->battery_id, rhs.battery_id);
	}
	return *this;
}

void Battery::set_capacity(int cap)
{
	this->capacity = cap;
}

void Battery::set_battery_id(const char* battery_id)
{
	delete[] this->battery_id;
	this->battery_id = new char[strlen(battery_id) + 1];
	strcpy(this->battery_id, battery_id);
}

int Battery::get_capacity() const
{
	return capacity;
}

const char* Battery::get_battery_id() const
{
	return this->battery_id;
}

std::ostream& operator<<(std::ostream& out, const Battery& bat)
{
	out << (CarPart&)bat;
	out << " - " << bat.battery_id << " - " << bat.capacity << " Ah";
	return out;
}
