#include "EventBase.h"


EventBase::EventBase(unsigned startH, unsigned startM, unsigned startS,
	unsigned endH, unsigned endM, unsigned endS)
{
	startTime = new Time(startH, startM, startS);
	endTime = new Time(endH, endM, endS);
}

EventBase::EventBase(const Time& inputStartTime, const Time& inputEndTime)
{
	*startTime = inputStartTime;
	*endTime = inputEndTime;
}

Time EventBase::getStartTime() const
{
	return *startTime;
}

void EventBase::setStartTime(const Time& inputStartTime)
{
	*startTime = inputStartTime;
}

Time EventBase::getEndTime() const
{
	return *endTime;
}

void EventBase::setEndTime(const Time& inputEndTime)
{
	*endTime = inputEndTime;
}