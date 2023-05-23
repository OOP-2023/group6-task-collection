#pragma once
class Event
{
protected:
	struct timesTamp
	{
		size_t hours;
		size_t minutes;
	};
	timesTamp _startTime;
	timesTamp _finalTime;
	virtual Event* clone() const = 0;
public:
	Event(size_t startTimeInHours, size_t startTimeInMinutes, size_t finalTimeInHours, size_t finalTimeInMinutes);
};

