//
// Created by swordypepe on 5/23/23.
//

#ifndef WEEK12_SIMPLEEVENT_H
#define WEEK12_SIMPLEEVENT_H

#include "EventBase.h"

class SimpleEvent : public EventBase
{
private:
    const double maxDuration = 6;
public:
    SimpleEvent(timeStamp startTime, timeStamp endTime);
    EventBase * clone() override;
};


#endif
