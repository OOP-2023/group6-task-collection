#pragma once
#ifndef _EVENTWITHFIXEDINTERMISSION_
#define _EVENTWITHFIXEDINTERMISSION_
#include <iostream>
#include "Event.h"

class EventWithFixedIntermission : public Event {
private:
	std::string intermissionStartTime;
	std::string intermissionEndTime;

	float calculateDuration() const;

public:
	EventWithFixedIntermission(const std::string& startTime, const std::string& intermissionStartTime,
		                       const std::string& intermissionEndTime, const std::string& endTime);
	bool isValid() const;
	void printDetails() const;

};

EventWithFixedIntermission::EventWithFixedIntermission(const std::string& startTime, const std::string& intermissionStartTime,
	                                                   const std::string& intermissionEndTime, const std::string& endTime) 
	                                                   : Event(startTime, endTime), intermissionStartTime(intermissionStartTime),
	                                                   intermissionEndTime(intermissionEndTime){}

bool EventWithFixedIntermission::isValid() const {

	if (calculateDuration() > 4.0) {
		return false;
	}

	return true;
}


void EventWithFixedIntermission::printDetails() const {
	std::cout << "Event with fixed Intermission "\n";
	std::cout << "Start Time: " << startTime << "\n";
	std::cout << "Intermission start time: " << intermissionStartTime << "\n";
	std::cout << "Intermission end time: " << intermissionEndTime << "\n";
	std::cout << "EndTime" << endTime << "\n";
}

float  EventWithFixedintermission::calculateDuration() const {

}


#endif 
