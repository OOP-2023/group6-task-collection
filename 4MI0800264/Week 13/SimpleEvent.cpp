#include "SimpleEvent.h"

void SimpleEvent::validate()
{
	if (duration > 7200)
		throw std::runtime_error("The Duration of this SimpleEvent is longer than 2 hours! \n");

	if (duration < 0)
		throw std::runtime_error("The startTime can not be later than the endTime! \n");
}

SimpleEvent::SimpleEvent(unsigned startH, unsigned startM, unsigned startS,
	unsigned endH, unsigned endM, unsigned endS) : EventBase(startH, startM, startS, endH, endM, endS)
{
	duration = getEndTime().convertToSeconds() - getStartTime().convertToSeconds();

	validate();
};

SimpleEvent::SimpleEvent(const Time& inputStartTime, const Time& inputEndTime) : EventBase(inputStartTime, inputEndTime)
{
	duration = getEndTime().convertToSeconds() - getStartTime().convertToSeconds();

	validate();

};

SimpleEvent::SimpleEvent(const SimpleEvent& other) : EventBase(other.getStartTime(), other.getEndTime())
{
	duration = getEndTime().convertToSeconds() - getStartTime().convertToSeconds();

	validate();

};


SimpleEvent& SimpleEvent::operator = (const SimpleEvent& other)
{
	if (this != &other)
	{
		setStartTime(other.getStartTime());
		setEndTime(other.getEndTime());
	}

	return *this;
}


int SimpleEvent::getDuration() const
{
	return duration;
}