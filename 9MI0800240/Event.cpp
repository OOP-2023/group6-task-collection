#include "Event.h"

Event::Event(size_t startTimeInHours, size_t startTimeInMinutes, size_t finalTimeInHours, size_t finalTimeInMinutes)
{
	_startTime.hours = startTimeInHours;
	_startTime.minutes = startTimeInMinutes;
	_finalTime.hours = finalTimeInHours;
	_finalTime.minutes = finalTimeInMinutes;
}
