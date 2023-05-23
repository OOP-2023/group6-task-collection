//
// Created by swordypepe on 5/23/23.
//

#include "EventManager.h"


void EventManager::addEvent(EventBase *other)
{
    collection[size++] = other->clone();
}

EventManager::EventManager()
{
    collection = new EventBase * [capacity];
}

EventManager::~EventManager()
{
    for (int i = 0; i < size; ++i)
    {
        delete collection[i];
    }
    delete[] collection;
}
