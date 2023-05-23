#pragma once
#ifndef _SIMPLEEVENT_
#define _SIMPLEEVENT_
#include "Event.h"
#include <iostream>

class SimpleEvent : public Event {
public: 
	SimpleEvent(const std::string& startTime, const std::string& endTime);
	bool isValid() const ;
	void printDetails() const;

private:
	float duration() const;
};

SimpleEvent::SimpleEvent(const std::string& startTime, const std::string& endTime) : Event(startTime, endTime){}

bool SimpleEvent::isValid() const {
	if (duration() > 2.0) {
		return false;
	}

	return true;
}

void SimpleEvent::printDetails() const {
	std::cout << "Simple Event: \n";
	std::cout << "Start Time: " << startTime << "\n";
	std::cout << "End Time: " << endTime << "\n";
	std::cout << "Duration: " << duration << "\n";

}

float SimpleEvent::duration() const {

}







#endif  
