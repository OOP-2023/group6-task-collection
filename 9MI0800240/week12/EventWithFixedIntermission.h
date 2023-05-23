#pragma once
#include"SimpleEvent.h"
class EventWithFixedIntermission : protected Event
{
private:
	timesTamp _startAntract;
	timesTamp _finalAntract;
public:
	EventWithFixedIntermission(size_t startTimeInHours, size_t startTimeInMinutes, size_t finalTimeInHours, size_t finalTimeInMinutes, size_t startAntractInHours, size_t startAntractInMinutes);
	EventWithFixedIntermission* clone() const override;
};

