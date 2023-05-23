#include "EventWithFixedIntermission.h"

void EventWithFixedIntermission::validate()
{

	if (duration > 14400)
		throw std::runtime_error("The Duration of this EventWithFixedIntermission is longer than 4 hours! \n");

	if (duration < 0)
		throw std::runtime_error("The startTime can not be later than the endTime! \n");

	if (antract->convertToSeconds() < getStartTime().convertToSeconds() ||
		antract->convertToSeconds() > getEndTime().convertToSeconds() ||
		antract->convertToSeconds() + 1200 > getEndTime().convertToSeconds())
		throw std::runtime_error("The antract must be between start and end times and not go beyond endTime! \n");
}

EventWithFixedIntermission::EventWithFixedIntermission(unsigned startH, unsigned startM, unsigned startS,
	unsigned endH, unsigned endM, unsigned endS, unsigned antractH, unsigned antractM, unsigned antractS) : EventBase(startH, startM, startS, endH, endM, endS)
{
	duration = getEndTime().convertToSeconds() - getStartTime().convertToSeconds();

	antract = new Time(antractH, antractM, antractS);

	validate();
};

EventWithFixedIntermission::EventWithFixedIntermission(const Time& inputStartTime, const Time& inputEndTime, const Time& inputAntract) : EventBase(inputStartTime, inputEndTime)
{
	duration = getEndTime().convertToSeconds() - getStartTime().convertToSeconds();

	antract = new Time(inputAntract);

	validate();
};

EventWithFixedIntermission::EventWithFixedIntermission(const EventWithFixedIntermission& other) : EventBase(other.getStartTime(), other.getEndTime())
{
	duration = getEndTime().convertToSeconds() - getStartTime().convertToSeconds();
	
	antract = new Time(other.getAntract());

	validate();

};


EventWithFixedIntermission& EventWithFixedIntermission::operator = (const EventWithFixedIntermission& other)
{
	if (this != &other)
	{
		setStartTime(other.getStartTime());
		setEndTime(other.getEndTime());
		antract = other.antract;
	}

	return *this;
}


int EventWithFixedIntermission::getDuration() const
{
	return duration;
}


Time EventWithFixedIntermission::getAntract() const
{
	return *antract;
}