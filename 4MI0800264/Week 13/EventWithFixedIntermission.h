#pragma once
#include "EventBase.h"

class EventWithFixedIntermission : public EventBase
{
	int duration;
	Time* antract;

	void validate();
public:

	EventWithFixedIntermission(unsigned startH, unsigned startM, unsigned startS,
		unsigned endH, unsigned endM, unsigned endS, unsigned antractH, unsigned antractM, unsigned antractS);

	EventWithFixedIntermission(const Time& inputStartTime, const Time& inputEndTime, const Time& inputAntract);

	EventWithFixedIntermission(const EventWithFixedIntermission& other);

	EventWithFixedIntermission& operator = (const EventWithFixedIntermission& other);

	int getDuration() const;

	Time getAntract() const;
};