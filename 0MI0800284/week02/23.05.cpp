
#include <iostream>
#include <cstring>
using namespace std;
#pragma warning (disable:4996)

class EventBase
{
	unsigned int startTime;
	unsigned int endTime;
	unsigned int maxTime;
public:
	EventBase(unsigned int _startHours, unsigned int _startMins, unsigned int _endHours, unsigned int _endMins);
	void isValid(unsigned int _maxTime, unsigned int antract)
	{
		if ((endTime - startTime-antract) > _maxTime)
		{
			throw "Error!";
		}
	}
	virtual EventBase* clone() const = 0;
	virtual~EventBase() = default;
};

EventBase ::EventBase(unsigned int _startHours, unsigned int _startMins, unsigned int _endHours, unsigned int _endMins)
{
     unsigned int startTime = _startHours * 60 + _startMins;
     unsigned int endTime = _endHours * 60 + _endMins;
}
class SimpleEvent: public EventBase
{
	const unsigned int maxTime = 120;
	const unsigned int antractTime = 20;

public:
	SimpleEvent(unsigned int _startHours, unsigned int _startMins, unsigned int _endHours, unsigned int _endMins);
	SimpleEvent* clone() const override;
};

SimpleEvent::SimpleEvent(unsigned int _startHours, unsigned int _startMins, unsigned int _endHours, unsigned int _endMins)
	:EventBase(_startHours, _startMins,   _endHours,   _endMins)
{
	isValid(maxTime, antractTime);
}

SimpleEvent* SimpleEvent::clone() const
{
	return new SimpleEvent(*this);
}

class EventWithFixedIntermission :public EventBase
{
public:
	EventWithFixedIntermission(unsigned int _startHours, unsigned int _startMins, unsigned int _endHours, unsigned int _endMins, unsigned int _startAntract);
	EventWithFixedIntermission* clone() const override;
private:
	unsigned int startAntract;
	const unsigned int maxTime = 240;
	const unsigned int antractTime=0;
};

EventWithFixedIntermission::EventWithFixedIntermission(unsigned int _startHours, unsigned int _startMins, unsigned int _endHours, unsigned int _endMins, unsigned int _startAntract)
	: EventBase(_startHours, _startMins,  _endHours,  _endMins)
{
	startAntract = _startAntract;
	isValid(maxTime, antractTime);
}

EventWithFixedIntermission* EventWithFixedIntermission::clone() const
{
	return new EventWithFixedIntermission(*this);
}

class EventWithIntermission : public EventBase
{
public:
	EventWithIntermission(unsigned int startAntract, unsigned int endAntract,unsigned int _startHours, unsigned int _startMins, unsigned int _endHours, unsigned int _endMins);
	EventWithIntermission* clone() const override;

private:
	unsigned int startAntract;
	unsigned int endAntract;
	const unsigned int maxTime = 360;
	unsigned int antractTime;
};

EventWithIntermission::EventWithIntermission(unsigned int _startAntract,unsigned int _endAntract, unsigned int _startHours, unsigned int _startMins, unsigned int _endHours, unsigned int _endMins):EventBase(_startHours, _startMins, _endHours, _endMins)
{
	startAntract = _startAntract;
	endAntract = _endAntract;
	antractTime = endAntract - startAntract;
	isValid(maxTime, antractTime);
}

EventWithIntermission* EventWithIntermission::clone() const
{
	return new EventWithIntermission(*this);
}

int main()
{
}

