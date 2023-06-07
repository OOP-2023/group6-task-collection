#pragma once
#include"Event.h"
class EventWithIntermission : protected Event
{
private:
	timesTamp _startAntract;
	timesTamp _finalAntract;
public:
	EventWithIntermission(size_t startTimeInHours, size_t startTimeInMinutes, size_t finalTimeInHours, size_t finalTimeInMinutes, size_t startAntractInHours, size_t startAntractInMinutes, size_t finalAntractInHours, size_t finalAntractInMinutes);
	EventWithIntermission* clone() const override;
};

