#include "EventWithIntermission.h"
#include<iostream>
EventWithIntermission::EventWithIntermission(size_t startTimeInHours, size_t startTimeInMinutes, size_t finalTimeInHours, size_t finalTimeInMinutes, size_t startAntractInHours, size_t startAntractInMinutes, size_t finalAntractInHours, size_t finalAntractInMinutes) 
	: Event(startTimeInHours, startTimeInMinutes, finalTimeInHours, finalTimeInMinutes)
{
	bool isValidTime = ((_finalTime.hours * 60 + _finalTime.minutes) - (_startTime.hours * 60 + _startTime.minutes)) <= 360;
	bool isValidTimeAntract = (finalAntractInHours + finalAntractInMinutes) - (startAntractInHours + startAntractInMinutes);
	
	if (isValidTime && (isValidTimeAntract >= 30 && isValidTimeAntract <=60))
	{
		_startAntract.hours = startAntractInHours;
		_startAntract.minutes = startAntractInMinutes;
		_finalAntract.hours = finalAntractInHours;
		_finalAntract.minutes = finalAntractInMinutes;
	}
	else
		throw std::exception("The time is invalid!");
}

EventWithIntermission* EventWithIntermission::clone() const
{
	return new EventWithIntermission(*this);
}
