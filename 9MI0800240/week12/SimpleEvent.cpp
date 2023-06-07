#include "SimpleEvent.h"
#include <iostream>

SimpleEvent::SimpleEvent(size_t startTimeInHours, size_t startTimeInMinutes, size_t finalTimeInHours, size_t finalTimeInMinutes) :
	Event(startTimeInHours, startTimeInMinutes, finalTimeInHours, finalTimeInMinutes)
{
	bool isValidTime = ((_finalTime.hours * 60 + _finalTime.minutes) - (_startTime.hours * 60 + _startTime.minutes)) <= 120;
	if (isValidTime)
	{
		_startTime.hours = startTimeInHours;
		_startTime.minutes = startTimeInMinutes;
		_finalTime.hours = finalTimeInHours;
		_finalTime.minutes = finalTimeInMinutes;
	}
	else
		throw std::exception("The time is invalid!");
}

SimpleEvent* SimpleEvent::clone() const
{
	return  new SimpleEvent(*this);
}
