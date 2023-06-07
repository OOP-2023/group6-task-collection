#ifndef _EVENT_H
#define _EVENT_H

class Events {
protected:
	unsigned startHour;
	unsigned startMinutes;
	unsigned endHour;
	unsigned endMinutes;
	virtual bool isLongEnough() const = 0;
	void setStartHour(unsigned);
	void setStartMins(unsigned);
	void setEndHour(unsigned);
	void setEndMins(unsigned);
public:
	bool isActiveInCertainTime(unsigned, unsigned) const;
	unsigned getStartHour() const;
	unsigned getStartMins() const;
	unsigned getEndHour() const;
	unsigned getEndMins() const;
	Events(unsigned, unsigned, unsigned, unsigned);
	virtual ~Events() = default;
	virtual Events* clone() const = 0;
};


class SimpleEvent : virtual public Events {
	bool isLongEnough() const override;
public:
	SimpleEvent(unsigned, unsigned, unsigned, unsigned);
	virtual ~SimpleEvent() = default;
	Events* clone() const override;
};

class EventWithFixedIntermission : virtual public Events {
protected:
	static const int interMissionLength = 20; //minutes
	unsigned startInterMissionHour;
	unsigned startInterMissionMins;
	unsigned endInterMissionHour;
	unsigned endInterMissionMins;
	bool isLongEnough() const override ;
public:
	EventWithFixedIntermission(unsigned, unsigned, unsigned, unsigned, unsigned, unsigned);
	virtual ~EventWithFixedIntermission() = default;
	Events* clone() const override;

};

class EventWithIntermission : public SimpleEvent, public EventWithFixedIntermission {
	bool isLongEnough()  const override ;
	bool isInterMissionLongEnough() const;
public:
	EventWithIntermission(unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned);
	virtual ~EventWithIntermission() = default;
	Events* clone() const override;
};


class EventManager {
	Events** data;
	size_t capacity;
	size_t index;
	void free();
	void copy(const EventManager&);
public:
	EventManager(size_t);
	~EventManager();
	EventManager(const EventManager&);
	EventManager& operator=(const EventManager&);
	bool addEvent(Events* event);
	bool isBusy(unsigned, unsigned) const;
	size_t onGoingEvents(unsigned, unsigned) const;

};
#endif