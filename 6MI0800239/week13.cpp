#include <iostream>

class Event {
protected:
    double startMinutes;
    double endMinunes;

    bool isValid() {}
public:
    Event(double start, double end) :startMinutes(start), endMinunes(end) {}
    Event()=default;

    virtual Event* clone() const = 0;
    virtual bool isOnPer(unsigned hours,unsigned min) const = 0;
    virtual ~Event() = default;
    virtual bool isValid() const = 0;

    const double getStart() const
    {
        return startMinutes;
    }

    const double getEnd() const
    {
        return endMinunes;
    }
};

class SimpleEvent :public Event {
public:
    SimpleEvent(double start, double end) :Event(start, end) {}

    Event* clone() const override
    {
        return new SimpleEvent(*this);
    }

    bool isValid() const override
    {
        return ((endMinunes - startMinutes) / 60) > 2.00;
    }

    bool isOnPer(unsigned hours,unsigned min) const override
    {
        unsigned time = hours * 60 + min;
        return time > startMinutes && time < endMinunes;
    }
};

class EventWithFixedIntermission :public Event {
    double startAnt;
public:
    EventWithFixedIntermission(double start, double end, double startAnt) :Event(start, end), startAnt(startAnt) { }

    Event* clone() const override
    {
        return new EventWithFixedIntermission(*this);
    }

    bool isValid() const override
    {
        return ((endMinunes - startMinutes - 20) / 60) > 4.00;
    }

    bool isOnPer(unsigned hours, unsigned min) const override
    {
        unsigned time = hours * 60 + min;
        return time > startMinutes && time < startAnt || time> startAnt+20 && time < endMinunes;
    }
};

class EventWithIntermission :public Event {
    double startAntract;
    double endOfAntract;
public:
    EventWithIntermission(double start, double end, double startAnt, double endAnt) :
        Event(start, end), startAntract(startAnt),endOfAntract(endAnt){}

    Event* clone() const override
    {
        return new EventWithIntermission(*this);
    }

    bool isValid() const override
    {
        return (((endMinunes - startMinutes) / 60) > 6.00) &&
            ((endOfAntract - startAntract) / 60 > 1.00 || (endOfAntract - startAntract) / 60 > 0.50);
    }

    bool isOnPer(unsigned hours, unsigned min) const override
    {
        unsigned time = hours * 60 + min;
        return time > startMinutes && time < startAntract || time> endOfAntract + 20 && time < endMinunes;
    }
};

class EventManiger {
    Event** events;
    int count;
    int capacity;

    void free()
    {
        for (size_t i = 0; i < count; i++)
            delete events[i];
        delete[] events;
    }

    void copyFrom(const EventManiger& other)
    {
        count = other.count;
        capacity = other.capacity;
        events = new Event * [capacity];
        for (size_t i = 0; i < count; i++)
        {
            events[i] = other.events[i]->clone();
        }
    }
public:
    EventManiger(const EventManiger& other)
    {
        copyFrom(other);
    }

    EventManiger& operator=(const EventManiger& other)
    {
        if (this!=&other)
        {
            free();
            copyFrom(other);
        }
        return *this;
    }

    ~EventManiger()
    {
        free();
    }

    void resize()
    {
        Event** newColl = new Event * [capacity *= 2];
        for (size_t i = 0; i < count; i++)
        {
            newColl[i] = events[i];
        }
        delete[] events;
        events = newColl;
    }

    void addEvent(const Event& current)
    {
        if (!current.isValid())
            throw std::exception("Not valid event!");
        if (count == capacity)
            resize();
        events[count++] = current.clone();
    }

    bool isBusy(unsigned hours, unsigned minutes)
    {
        unsigned timeInMin = hours * 60 + minutes;
        bool isbusy=false;
        for (size_t i = 0; i < count; i++)
        {
            if (timeInMin >= events[i]->getStart() && timeInMin <= events[i]->getEnd())
                isbusy = true;
        }
        return isbusy;
    }

    unsigned ongoingEvents(unsigned hours, unsigned minutes)
    {
        unsigned counter = 0;
        for (size_t i = 0; i < count; i++)
        {
            if (events[i]->isOnPer(hours, minutes))
                counter++;
        }
        return counter;
    }
};


int main()
{
    
}

