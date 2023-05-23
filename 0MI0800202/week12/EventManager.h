//
// Created by swordypepe on 5/23/23.
//

#ifndef WEEK12_EVENTMANAGER_H
#define WEEK12_EVENTMANAGER_H

#include <vector>
#include "SimpleEvent.h"
#include "EventWithIntermission.h"

class EventManager
{
private:
    int size;
    const int capacity = 16;
    EventBase** collection;
public:
    EventManager();
    ~EventManager();
    void addEvent(EventBase* other);
};


#endif //WEEK12_EVENTMANAGER_H
