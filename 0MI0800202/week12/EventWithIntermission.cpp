//
// Created by swordypepe on 5/23/23.
//

#include <stdexcept>
#include "EventWithIntermission.h"

EventWithIntermission::EventWithIntermission(EventBase::timeStamp startTime, EventBase::timeStamp endTime, timeStamp _startInter, timeStamp _endInter) : EventBase(startTime, endTime)
{
    if (endTime.hrs - startTime.hrs > maxDuration)
    {
        throw std::runtime_error("wrong data given");
    }
    if (_endInter.hrs - _startInter.hrs > maxInter);
    startTime.hrs = _startInter.hrs;
    endTime.mins = _endInter.mins;
}


EventBase *EventWithIntermission::clone()
{
    return new EventWithIntermission(*this);
}
