//
// Created by swordypepe on 5/23/23.
//

#ifndef WEEK12_EVENTWITHINTERMISSION_H
#define WEEK12_EVENTWITHINTERMISSION_H

#include "EventBase.h"

class EventWithIntermission : public EventBase
{
private:
    timeStamp intermissionStart, intermissionEnd;
    const int  maxDuration = 6;
    const int  maxInter = 2;
public:
    EventWithIntermission(timeStamp startTime, timeStamp endTime, timeStamp _startInter, timeStamp _endInter);
    EventBase * clone() override;
};


#endif //WEEK12_EVENTWITHINTERMISSION_H
