#pragma once
#include "EventBase.h"
#include "SimpleEvent.h"

class EventWithIntermission : public EventBase
{
	int duration;
	SimpleEvent* antract;

	void validate();

public:

	EventWithIntermission(unsigned startH, unsigned startM, unsigned startS,
		unsigned endH, unsigned endM, unsigned endS,
		unsigned antractStartH, unsigned antractStartM, unsigned antractStartS,
		unsigned antractEndH, unsigned antractEndM, unsigned antractEndS);

	EventWithIntermission(const Time& inputStartTime, const Time& inputEndTime, const Time& intermissionStartTime, const Time& intermissionEndTime);

	EventWithIntermission(const EventWithIntermission& other);

	EventWithIntermission& operator = (const EventWithIntermission& other);

	int getDuration() const;

	SimpleEvent getAntract() const;
};