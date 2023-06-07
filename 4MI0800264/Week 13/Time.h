#pragma once
#include <iostream>

struct Time
{
private:
	void copy(const Time& other)
	{
		hours = other.hours % 24;
		mins = other.mins % 60;
		seconds = other.seconds % 60;
	}
public:
	int hours;
	int mins;
	int seconds;

	Time(unsigned inputHours, unsigned inputMins, unsigned inputSeconds)
	{

		hours = inputHours % 24;
		mins = inputMins % 60;
		seconds = inputSeconds % 60;
	}

	Time(const Time& other)
	{
		copy(other);
	}

	Time& operator = (const Time& other)
	{
		if (this != &other)
		{
			copy(other);
		}

		return *this;
	}

	int convertToSeconds()
	{
		return ((hours * 3600) + (mins * 60) + seconds);
	}
};
