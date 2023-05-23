#ifndef EVENT_H
#define EVENT_H

class Event {
protected:
    int startHour;
    int startMinute;

public:
    Event(int hour, int minute);

    virtual void validateEvent() = 0;
};

class SimpleEvent : public Event {
private:
    int endHour;
    int endMinute;

public:
    SimpleEvent(int startHour, int startMinute, int endHour, int endMinute);

    void validateEvent() override;
};

class EventWithFixedIntermission : public Event {
private:
    int intermissionStartHour;
    int intermissionStartMinute;
    int intermissionEndHour;
    int intermissionEndMinute;
    int endHour;
    int endMinute;

public:
    EventWithFixedIntermission(int startHour, int startMinute, int intermissionStartHour, int intermissionStartMinute,
        int intermissionEndHour, int intermissionEndMinute, int endHour, int endMinute);

    void validateEvent() override;
};

class EventWithIntermission : public Event {
private:
    int intermissionStartHour;
    int intermissionStartMinute;
    int intermissionEndHour;
    int intermissionEndMinute;
    int endHour;
    int endMinute;

public:
    EventWithIntermission(int startHour, int startMinute, int intermissionStartHour, int intermissionStartMinute,
        int intermissionEndHour, int intermissionEndMinute, int endHour, int endMinute);

    void validateEvent() override;
};

#endif  // EVENT_H