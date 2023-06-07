#include "EventWithIntermission.h"

void EventWithIntermission::validate()
{
	if (duration > 21600)
		throw std::runtime_error("The Duration of this EventWithIntermission is longer than 4 hours! \n");

	if (duration < 0)
		throw std::runtime_error("The startTime can not be later than the endTime! \n");

	if (antract->getDuration() < 1800 || antract->getDuration() > 3600)
		throw std::runtime_error("The Intermission's length must be between 30 minutes and 1 hour! \n");

	if (antract->getStartTime().convertToSeconds() < getStartTime().convertToSeconds() ||
		antract->getEndTime().convertToSeconds() > getEndTime().convertToSeconds() ||
		antract->getStartTime().convertToSeconds() + antract->getDuration() > getEndTime().convertToSeconds())
		throw std::runtime_error("The intermission must be between start and end times and not go beyond endTime! \n");
}

EventWithIntermission::EventWithIntermission(unsigned startH, unsigned startM, unsigned startS,
	unsigned endH, unsigned endM, unsigned endS, 
	unsigned antractStartH, unsigned antractStartM, unsigned antractStartS,
	unsigned antractEndH, unsigned antractEndM , unsigned antractEndS) : EventBase(startH, startM, startS, endH, endM, endS)
{
	duration = getEndTime().convertToSeconds() - getStartTime().convertToSeconds();

	antract = new SimpleEvent(antractStartH, antractStartM, antractStartS, antractEndH, antractEndM, antractEndS);

	validate();
};

EventWithIntermission::EventWithIntermission(const Time& inputStartTime, const Time& inputEndTime
											, const Time& intermissionStartTime, const Time& intermissionEndTime) : EventBase(inputStartTime, inputEndTime)
{
	duration = getEndTime().convertToSeconds() - getStartTime().convertToSeconds();

	antract = new SimpleEvent(intermissionStartTime, intermissionEndTime);

	validate();
};

EventWithIntermission::EventWithIntermission(const EventWithIntermission& other) : EventBase(other.getStartTime(), other.getEndTime())
{
	duration = getEndTime().convertToSeconds() - getStartTime().convertToSeconds();

	antract = new SimpleEvent(other.getAntract());

	validate();

};


EventWithIntermission& EventWithIntermission::operator = (const EventWithIntermission& other)
{
	if (this != &other)
	{
		setStartTime(other.getStartTime());
		setEndTime(other.getEndTime());
		antract = other.antract;
	}

	return *this;
}


int EventWithIntermission::getDuration() const
{
	return duration;
}


SimpleEvent EventWithIntermission::getAntract() const
{
	return *antract;
}