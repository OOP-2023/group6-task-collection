#pragma once

#include "Time.h"

class EventBase
{
	Time* startTime,* endTime;

public:

	EventBase(unsigned startH, unsigned startM, unsigned startS,
		unsigned endH, unsigned endM, unsigned endS);

	EventBase(const Time& inputStartTime, const Time& inputEndTime);
	
	Time getStartTime() const ;

	void setStartTime(const Time& inputStartTime);

	Time getEndTime() const;

	void setEndTime(const Time& inputEndTime);

};