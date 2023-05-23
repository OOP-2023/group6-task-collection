// Prakt_13.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

struct Hour
{
    int hour;
    int mins;

    int assertHour(int hour)
    {
        if (hour >= 24)
            return hour - 24;
    }
    void printHour() const
    {
        if (hour < 10)
            std::cout << "0";
        std::cout << hour << ":";
        if (mins < 10)
            std::cout << "0";
        std::cout << mins << std::endl;
    }

    Hour(int hour, int mins) :hour(hour), mins(mins) {};

    Hour operator+ (unsigned timeInMins)
    {
        int newHour = assertHour(this->hour + timeInMins / 60);
        int newMins = this->mins + timeInMins % 60;
        if (newMins >= 60)
        {
            newHour++;
            newMins -= 60;
        }

        return Hour(newHour, newMins);

    }

    bool operator>= (const Hour& other) const
    {
        return hour > other.hour || hour == other.hour && mins >= other.mins;
    }
    bool operator<=(const Hour& other) const
    {
        return hour < other.hour || hour == other.hour && mins <= other.mins;
    }

    friend unsigned operator- (const Hour& first, const Hour& second);
    
};

unsigned operator- (const Hour& first, const Hour& second)
{
    return (first.hour - second.hour) * 60 + (first.mins - second.mins);
}


class Event
{
    Hour startHour;
    Hour endHour;
    unsigned maxDuration;

    unsigned assertEventDuration(unsigned duration)
    {
        if ((endHour - startHour) > duration)
            throw std::out_of_range("over the duration!");

        return duration;
    }


public:
    Event(Hour startHour, Hour endHour, unsigned maxDuration) : startHour(startHour), endHour(endHour), maxDuration(assertEventDuration(maxDuration)) {};

    virtual Event* clone() const = 0;

    virtual ~Event();

    void print() const
    {
        std::cout << "Start: ";
        startHour.printHour();
        std::cout << "Finish: ";
        endHour.printHour();
    }

    bool isTheEventContainingSpecificHour(const Hour& hour)
    {
        return hour >= startHour && hour <= endHour;
    }

};

class SimpleEvent : public Event
{
public:
    SimpleEvent(Hour startHour, Hour endHour) : Event(startHour, endHour, 120) {}; //the duration is in minutes

    Event* clone() const
    {
        return new SimpleEvent(*this);
    }
};

struct Intermission
{
    Hour startIntermission;
    Hour endIntermission;
    unsigned intermissionDuration;

    Hour setEndIntermission(unsigned intermissionDuration)
    {
        return startIntermission + intermissionDuration;
    }
    unsigned setIntermissionDurationByTheStartAndTheEnd(unsigned minDuration, unsigned maxDuration)
    {
        if (minDuration != 0 && maxDuration != 0)
        {
            unsigned duration = endIntermission - startIntermission;
            if (duration >= minDuration && duration <= maxDuration)
                return duration;
            else
                throw std::out_of_range("Intermission out of range!");
        }
        else
            return endIntermission - startIntermission;
           
    }
    

    Intermission(Hour startIntermission, unsigned intermissionDuration)
        : startIntermission(startIntermission), intermissionDuration(intermissionDuration),
        endIntermission(setEndIntermission(intermissionDuration)) {};
    Intermission(Hour startIntermission, Hour endIntermission, unsigned minIntermissionDuration, unsigned maxIntermissionDuration)
        : startIntermission(startIntermission), endIntermission(endIntermission),
        intermissionDuration(setIntermissionDurationByTheStartAndTheEnd(minIntermissionDuration, maxIntermissionDuration)) {};




};
class EventWithFixedIntermission : public Event
{
    Intermission intermission;

public:
    EventWithFixedIntermission(Hour startHour, Hour endHour, Hour startIntermission)
        : Event(startHour, endHour, 240),
        intermission(startIntermission, 20) {};

    Event* clone() const
    {
        return new EventWithFixedIntermission(*this);
    }
    
};

class EventWithIntermission : public Event
{
    Intermission intermission;

public:
    EventWithIntermission(Hour startHour, Hour endHour, Hour startIntermission, Hour endIntermission)
        : Event(startHour, endHour, 360),
        intermission(startIntermission, endIntermission, 30, 60) {};

    Event* clone() const
    {
        return new EventWithIntermission(*this);
    }

};

class EventManager
{
    Event** events;
    size_t count;
    size_t capacity;

    void copyFrom(const EventManager& other)
    {
        count = other.count;
        capacity = other.capacity;
        events = new Event * [capacity];
        for (size_t i = 0; i < count; i++)
            events[i] = other.events[i]->clone();

    }
    void free()
    {
        delete[] events;
    }

    void resize()
    {
        capacity = capacity * 2;
        EventManager newEM(events, count, capacity);
        *this = newEM;
    }

public:
    EventManager(Event** events, size_t count, size_t capacity) : count(count), capacity(capacity)
    {
        this->events = new Event * [capacity];
        for (size_t i = 0; i < count; i++)
        {
            this->events[i] = events[i]->clone();
        }
    }
    EventManager(const EventManager& other)
    {
        copyFrom(other);
    }
    EventManager& operator=(const EventManager& other)
    {
        if (this != &other)
        {
            free();
            copyFrom(other);
        }
        return *this;
    }
    ~EventManager()
    {
        free();
    }

    void addEvent(const Event& event)
    {
        if (count == capacity)
            resize();

        events[count++] = event.clone();

    }
    bool isBusy(unsigned hrs, unsigned mins)
    {
        Hour checkHour(hrs, mins);
        for (size_t i = 0; i < count; i++)
        {
            if (events[i]->isTheEventContainingSpecificHour(checkHour))
                return true;
        }
        return false;
    }
    unsigned onGoingEvents(const Hour& hour)
    {
        unsigned counter = 0;

        for (size_t i = 0; i < count; i++)
        {
            if (events[i]->isTheEventContainingSpecificHour(hour))
                counter++;
        }

        return counter;
    }
};

int main()
{
    

}

