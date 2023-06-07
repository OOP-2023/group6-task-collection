#pragma once
#include "Event.h"
class SimpleEvent : protected Event
{
public:
	SimpleEvent(size_t startTimeInHours, size_t startTimeInMinutes, size_t finalTimeInHours, size_t finalTimeInMinutes);
	SimpleEvent* clone() const override;
	virtual ~SimpleEvent() = default;
};

