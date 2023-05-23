//
// Created by swordypepe on 5/23/23.
//

#include "SimpleEvent.h"
#include <iostream>

SimpleEvent::SimpleEvent( timeStamp startTime, timeStamp endTime)
        : EventBase(startTime, endTime)
{
    if ( endTime.hrs - startTime.hrs > maxDuration)
    {
        throw std::runtime_error("wrong data given");
    }
}

EventBase *SimpleEvent::clone()
{
    return new SimpleEvent(*this);
}


