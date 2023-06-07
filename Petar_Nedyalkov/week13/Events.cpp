#include <iostream>
#include "Events.h"

// class Events
bool Events::isActiveInCertainTime(unsigned hour, unsigned mins) const {
	unsigned _startMinutes = startHour * 60 + startMinutes;
	unsigned _endMinutes = endHour * 60 + endMinutes;
	unsigned currentMinutes = hour * 60 + mins;
	return currentMinutes >= _startMinutes && currentMinutes <= _endMinutes;

}

Events::Events(unsigned _startHour, unsigned _startMins, unsigned _endHour, unsigned _endMins) {
	setStartHour(_startHour);
	setStartMins(_startMins);
	setEndHour(_endHour);
	setEndMins(_endMins);
}

void Events::setStartHour(unsigned hour) {
	if (hour < 0 || hour > 23)
		throw std::invalid_argument("Invalid hour!");
	else startHour = hour;
}
void Events::setStartMins(unsigned mins) {
	if (mins < 0 || mins > 60)
		throw std::invalid_argument("Invalid minutes!");
	else startMinutes = mins;
}
void Events::setEndHour(unsigned hour) {
	if (hour < 0 || hour > 23)
		throw std::invalid_argument("Invalid hour!");
	else endHour = hour;
}
void Events::setEndMins(unsigned mins) {
	if (mins < 0 || mins > 60)
		throw std::invalid_argument("Invalid minutes!");
	else endMinutes = mins;
}

unsigned Events::getStartHour() const {
	return startHour;
}

unsigned Events::getStartMins() const {
	return startMinutes;
}

unsigned Events::getEndHour() const {
	return endHour;
}

unsigned Events::getEndMins() const {
	return endMinutes;
}
// class SimpleEvents
bool SimpleEvent::isLongEnough() const{
	if ((endHour * 60 + endMinutes) - (startHour * 60 + startMinutes) <= 120) return true;
	else return false;
}

SimpleEvent::SimpleEvent(unsigned _startHour, unsigned _startMins, unsigned _endHour, unsigned _endMins) : Events(_startHour, _startMins, _endHour, _endMins) {
}

Events* SimpleEvent::clone() const {
	return new SimpleEvent(*this);
}

// class EventWithFixedIntermission
bool EventWithFixedIntermission::isLongEnough() const {
	if ((endHour * 60 + endMinutes) - (startHour * 60 + startMinutes) <= 240) return true;
	else return false;
}

EventWithFixedIntermission::EventWithFixedIntermission(unsigned _startHour, unsigned _startMins, unsigned _endHour, unsigned _endMins, unsigned _startInterHour, unsigned _startInterMins) : Events(_startHour, _startMins, _endHour, _endMins) {
	
	startInterMissionHour = _startInterHour;
	startInterMissionMins = _startInterMins;
	endInterMissionMins = startInterMissionMins + interMissionLength;
	endInterMissionHour = startInterMissionHour + endInterMissionMins / 60;
	endInterMissionMins %= 60;
}

Events* EventWithFixedIntermission::clone() const {
	return new EventWithFixedIntermission(*this);
}

//class EventWithIntermission
bool EventWithIntermission::isLongEnough() const {
	if ((endHour * 60 + endMinutes) - (startHour * 60 + startMinutes) <= 360) return true;
	else return false;
}

bool EventWithIntermission::isInterMissionLongEnough() const {
	unsigned totalTime = (endInterMissionHour * 60 + endInterMissionMins) - (startInterMissionHour * 60 + startInterMissionMins);
	
	if ( totalTime >= 30 && totalTime <=60) return true;
	else return false;
}

EventWithIntermission::EventWithIntermission(unsigned _startHour, unsigned _startMins, unsigned _endHour, unsigned _endMins, unsigned _startInterHour, unsigned _startInterMins, unsigned _endInterHour, unsigned _endInterMins) 
	: Events(_startHour, _startMins, _endHour, _endMins), SimpleEvent(_startHour, _startMins, _endHour, _endMins), EventWithFixedIntermission(_startHour, _startMins, _endHour, _endMins, _startInterHour, _startInterMins) {

	endInterMissionHour = _endInterHour;
	endInterMissionMins = _endInterMins;
}

Events* EventWithIntermission::clone() const {
	return new EventWithIntermission(*this);
}