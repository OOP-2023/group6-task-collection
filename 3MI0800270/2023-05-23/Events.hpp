#include <vector>

class Event {
public:
    unsigned startHour;
    unsigned startMin;
    unsigned endHour;
    unsigned endMin;
    Event(unsigned startHour, unsigned startMin, unsigned endHour, unsigned endMin) {
        if (startHour > 23 || startMin > 59 || endHour > 24 || endMin > 59) {
            throw "invalid hour";
        }
        this->startHour = startHour;
        this->startMin = startMin;
        this->endHour = endHour;
        this->endMin = endMin;
    }
    virtual Event* clone() const = 0;
    bool isRunning(unsigned hrs, unsigned min) {
        return (startHour * 100 + startMin < hrs * 100 + min) && (hrs * 100 + min < endHour * 100 + endMin);
    }
};

class SimpleEvent : public Event {
public:
    SimpleEvent(unsigned startHour, unsigned startMin, unsigned endHour, unsigned endMin) : Event(startHour, startMin, endHour, endMin) {
        if (startHour * 100 + startMin > endHour * 100 + endMin) {
            throw "invalid hours";
        }
        if (-(startHour * 100 + startMin) + (endHour * 100 + endMin) > 200) {
            throw "invalid hours";
        }
    }
    virtual Event* clone() const {
        return new SimpleEvent(*this);
    }
};

class EventWithIntermission : public Event {
public:
    unsigned atrHour;
    unsigned atrMin;
    unsigned atrEndHour;
    unsigned atrEndMin;
    EventWithIntermission(unsigned startHour, unsigned startMin, unsigned endHour, unsigned endMin, unsigned atrHour, unsigned artMin, unsigned atrEndHour, unsigned atrEndMin) : Event(startHour, startMin, endHour, endMin) {
        if (startHour * 100 + startMin > atrHour * 100 + atrMin || endHour * 100 + endMin < atrHour * 100 + atrMin || startHour * 100 + startMin > atrEndHour * 100 + atrEndMin
            || endHour * 100 + endMin < atrEndHour * 100 + atrEndMin || atrHour * 100 + atrMin > atrEndHour * 100 + atrEndMin) {
            throw "invalid hour";
        }
        if (atrHour * 100 + atrMin - (atrEndHour * 100 + atrEndMin) < 30 || atrHour * 100 + atrMin - (atrEndHour * 100 + atrEndMin) > 100) {
            throw "invalid hour";
        }
        if (-(startHour * 100 + startMin) + (endHour * 100 + endMin) - (atrHour * 100 + atrMin - (atrEndHour * 100 + atrEndMin)) > 600) {
            throw "invalid hours";
        }
        this->atrHour = atrHour;
        this->atrMin = atrMin;
        this->atrEndHour = atrEndHour;
        this->atrEndMin = atrEndMin;
    }
    virtual Event* clone() const {
        return new EventWithIntermission(*this);
    }
};

class EventWithFixedIntermission : public Event {
public:
    unsigned atrHour;
    unsigned atrMin;
    EventWithFixedIntermission(unsigned startHour, unsigned startMin, unsigned endHour, unsigned endMin, unsigned atrHour, unsigned artMin) : Event(startHour, startMin, endHour, endMin) {
        if (startHour * 100 + startMin > atrHour * 100 + atrMin || endHour * 100 + endMin < atrHour * 100 + atrMin) {
            throw "invalid hour";
        }
        if (startHour * 100 + startMin - (endHour * 100 + endMin) - 20 > 400) {
            throw "invalid hours";
        }
        this->atrHour = atrHour;
        this->atrMin = atrMin;
    }
    virtual Event* clone() const {
        return new EventWithFixedIntermission(*this);
    }
};

class EventManager {
public:
    std::vector<Event*> events;
    void addEvent(Event& event) {
        events.push_back(event.clone());
    }
    bool isBusy(unsigned hrs, unsigned min) {
        for (Event* ptr : events) {
            if (ptr->isRunning(hrs, min)) {
                return true;
            }
        }
        return false;
    }
    ~EventManager() {
        for (Event* ptr : events) {
            delete ptr;
        }
    }
};
