#include "EventWithFixedIntermission.h"
#include <iostream>
EventWithFixedIntermission::EventWithFixedIntermission(size_t startTimeInHours, size_t startTimeInMinutes, size_t finalTimeInHours, size_t finalTimeInMinutes, 
	size_t startAntractInHours, size_t startAntractInMinutes)
	: Event(startTimeInHours,startTimeInMinutes, finalTimeInHours,finalTimeInMinutes)
{
	bool isValidTime = ((_finalTime.hours * 60 + _finalTime.minutes) - (_startTime.hours * 60 + _startTime.minutes)) <= 240;
	if (isValidTime)
	{
		_startAntract.hours = startAntractInHours;
		_startAntract.minutes = startAntractInMinutes;
		size_t finalAntract = ((startAntractInHours * 60) + startAntractInMinutes) + 20;
		_finalAntract.hours = finalAntract / 60;
		_finalAntract.minutes = finalAntract % 60;
	}
	else
		throw std::exception("The time is invalid!");
}

EventWithFixedIntermission* EventWithFixedIntermission::clone() const 
{
	return new EventWithFixedIntermission(*this);
}
