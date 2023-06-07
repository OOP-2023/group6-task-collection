#ifndef _TIMEEVENTS_HPP
#define _TIMEEVENTS_HPP

#include <string>
#include <stddef.h>
#include <vector>
#include<algorithm>
class Event {
    size_t start; // 0...24*60
    size_t duration;
public:
    Event(size_t _start, size_t _duration, size_t max_duration) {
        if (_duration >= 0 && _duration <= max_duration) duration = _duration;
        if (_start >= 0 && _start <= 24 * 60) start = _start;
    }

    virtual ~Event() {}

    virtual Event* clone() const = 0;
    virtual bool isGoing(size_t) const = 0;

    void setDuration(size_t new_duration) { duration = new_duration; }
    void setStart(size_t new_start) { start = new_start; }

    size_t getDuration() const { return duration; }
    size_t getStart() const { return start; }
};

class SimpleEvent : public Event {
public:
    SimpleEvent(size_t start, size_t duration) : Event(start, duration, 2 * 60) {}
    SimpleEvent* clone() const override { return new SimpleEvent(*this); }

    ~SimpleEvent() override {}

    bool isGoing(size_t time) const override {
        int start = getStart();

        int duration = getDuration();
        if (start >= time && time <= start + duration) return true;
        else return false;
    }
};

class EventWithFixedIntermission : public Event {
private:
    size_t intermissionStart;
public:
    EventWithFixedIntermission(size_t start, size_t duration, size_t intermission_start) : Event(start, duration, 4 * 60) {
        if (intermission_start + 20 <= getDuration() && getDuration() >= intermission_start + 20) intermissionStart = getStart() + intermission_start;
        else intermissionStart = getStart() + getDuration() / 2;
    }
    EventWithFixedIntermission* clone() const override { return new EventWithFixedIntermission(*this); }
    ~EventWithFixedIntermission() override {}
    bool isGoing(size_t time) const override {
        int start = getStart();

        int duration = getDuration();
        if (start <= time && time <= start + duration) {
            if (intermissionStart <= time && time <= intermissionStart + 20) return false;
            else return true;
        }
        else return false;
    }


};

class EventWithIntermission : public Event {
private:
    size_t intermissionStart;
    size_t intermissionDuration;

public:
    EventWithIntermission(size_t start, size_t duration, size_t intermission_start, size_t intermission_duration) : Event(start, duration, 4 * 60) {
        if (intermission_duration > 60 || intermission_duration < 30) intermissionDuration = 30;
        else intermissionDuration = intermission_duration;

        if (intermission_start + intermissionDuration <= getDuration() && getDuration() >= intermission_start + intermissionDuration) intermissionStart = getStart() + intermission_start;
        else intermissionStart = getStart() + getDuration() / 2;
    }
    EventWithIntermission* clone() const override { return new EventWithIntermission(*this); }
    ~EventWithIntermission() override {}

    bool isGoing(size_t time) const override {
        int start = getStart();

        int duration = getDuration();
        if (start <= time && time <= start + duration) {
            if (intermissionStart <= time && time >= intermissionStart + intermissionDuration) return false;
            else return true;
        }
        else return false;
    }

};

class EventManager {
private:
    Event** events;
    size_t size;
    size_t capacity;

    void sortEvents(){
        for (size_t i = 0; i < size; i++)
        {
            for (size_t j = i+1; j < size; j++)
            {
                if(events[i]->getStart()+events[i]->getDuration() > events[j]->getStart()+events[j]->getDuration()){
                    std::swap(events[i], events[j]);
                }
            }
            
        }
    }

public:
    EventManager(size_t _capacity) {
        size = 0;
        capacity = _capacity;
        events = new Event * [capacity] {0};
    }

    ~EventManager(){
        for (size_t i = 0; i < size; i++)
        {
            delete events[i];
        }
        delete[] events;
        events = nullptr;
    }

    bool addEvent(const Event& event) {
        if (capacity == size) return false;
        events[size++] = event.clone();
        return true;
    }
    size_t ongoingEvents(size_t hour) {
        size_t count = 0;
        for (size_t i = 0; i < size; i++)
        {
            if (events[i]->isGoing(hour * 60)) count++;
        }
        return count;
    }

    std::vector<Event*> maxEvents() {
        sortEvents();
        std::vector<Event*> ans;

        ans.push_back(events[0]);

        int prevIndx = 0;
        for (size_t i = 1; i < size; i++)
        {
            if(events[i]->getStart() < events[prevIndx]->getStart()+events[prevIndx]->getDuration()) continue;
            ans.push_back(events[i]);
            prevIndx = i;
        }
        
    }
};

#endif // _TIMEEVENTS_HPP