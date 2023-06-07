#include "EventBase.h"

EventBase::EventBase(timeStamp _startTime, timeStamp _endTime)
{
    startTime.hrs = _startTime.hrs;
    endTime.hrs = _endTime.hrs;
    startTime.mins = _startTime.mins;
    endTime.mins = _endTime.mins;
}

EventBase::EventBase(EventBase &other)
{
    startTime = other.startTime;
    endTime = other.endTime;
}
