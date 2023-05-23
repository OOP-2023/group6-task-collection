#pragma once
#include "Time.h"
#include "EventBase.h"

class SimpleEvent : public EventBase
{
	int duration;

	void validate();

public:

	SimpleEvent(unsigned startH, unsigned startM, unsigned startS,
		unsigned endH , unsigned endM, unsigned endS);

	SimpleEvent(const Time& inputStartTime, const Time& inputEndTime);

	SimpleEvent(const SimpleEvent& other);

	SimpleEvent& operator = (const SimpleEvent& other);

	int getDuration() const;
};