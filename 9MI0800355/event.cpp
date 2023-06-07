#include "event.h"
#include <stdexcept>

Event::Event(int hour, int minute) : startHour(hour), startMinute(minute) {}

SimpleEvent::SimpleEvent(int startHour, int startMinute, int endHour, int endMinute)
    : Event(startHour, startMinute), endHour(endHour), endMinute(endMinute) {}

void SimpleEvent::validateEvent() {
    int startTotalMinutes = startHour * 60 + startMinute;
    int endTotalMinutes = endHour * 60 + endMinute;

    if (endTotalMinutes - startTotalMinutes > 120)
        throw std::runtime_error("SimpleEvent duration should not exceed 2 hours.");
}

EventWithFixedIntermission::EventWithFixedIntermission(int startHour, int startMinute, int intermissionStartHour,
    int intermissionStartMinute, int intermissionEndHour,
    int intermissionEndMinute, int endHour, int endMinute)
    : Event(startHour, startMinute), intermissionStartHour(intermissionStartHour),
    intermissionStartMinute(intermissionStartMinute), intermissionEndHour(intermissionEndHour),
    intermissionEndMinute(intermissionEndMinute), endHour(endHour), endMinute(endMinute) {}

void EventWithFixedIntermission::validateEvent() {
    int startTotalMinutes = startHour * 60 + startMinute;
    int intermissionStartTotalMinutes = intermissionStartHour * 60 + intermissionStartMinute;
    int intermissionEndTotalMinutes = intermissionEndHour * 60 + intermissionEndMinute;
    int endTotalMinutes = endHour * 60 + endMinute;

    int eventDuration = endTotalMinutes - startTotalMinutes;
    int intermissionDuration = intermissionEndTotalMinutes - intermissionStartTotalMinutes;

    if (eventDuration - intermissionDuration > 240)
        throw std::runtime_error("EventWithFixedIntermission duration (excluding intermission time) should not exceed 4 hours.");
}

EventWithIntermission::EventWithIntermission(int startHour, int startMinute, int intermissionStartHour,
    int intermissionStartMinute, int intermissionEndHour,
    int intermissionEndMinute, int endHour, int endMinute)
    : Event(startHour, startMinute), intermissionStartHour(intermissionStartHour),
    intermissionStartMinute(intermissionStartMinute), intermissionEndHour(intermissionEndHour),
    intermissionEndMinute(intermissionEndMinute), endHour(endHour), endMinute(endMinute) {}

void EventWithIntermission::validateEvent() {
    int startTotalMinutes = startHour * 60 + startMinute;
    int intermissionStartTotalMinutes = intermissionStartHour * 60 + intermissionStartMinute;
    int intermissionEndTotalMinutes = intermissionEndHour * 60 + intermissionEndMinute;
    int endTotalMinutes = endHour * 60 + endMinute;

    int eventDuration = endTotalMinutes - startTotalMinutes;
    int intermissionDuration = intermissionEndTotalMinutes - intermissionStartTotalMinutes;

    if (eventDuration - intermissionDuration > 360)
        throw std::runtime_error("EventWithIntermission duration (excluding intermission time) should not exceed 6 hours.");

    if (intermissionDuration < 30 || intermissionDuration > 60)
        throw std::runtime_error("EventWithIntermission intermission duration should be between 30 minutes and 1 hour.");
}
