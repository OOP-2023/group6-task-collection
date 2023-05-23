//
// Created by swordypepe on 5/23/23.
//

#ifndef WEEK12_EVENTBASE_H
#define WEEK12_EVENTBASE_H


#include <cstddef>

class EventBase
{
protected:
public:
    struct timeStamp
    {
        size_t hrs;
        size_t mins;
    };
    timeStamp startTime, endTime;
    EventBase(timeStamp startTime, timeStamp endTime);
    EventBase(EventBase& other);
    virtual ~EventBase() = default;
    virtual EventBase* clone() = 0;
};


#endif //WEEK12_EVENTBASE_H
