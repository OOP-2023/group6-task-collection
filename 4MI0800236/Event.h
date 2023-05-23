#pragma once
#ifndef _EVENT_
#define _EVENT_
#include <string>


class Event {
protected: 
	std::string startTime;
	std::string endTime;

public:
	Event(const std::string& startTime, const std::string& endTime);
	virtual bool isvalid() const = 0;
	virtual void printDetails() const = 0;
	virtual ~Event(){}
};

Event::Event(const std::string& startTime, const std::string& endTime):startTime(startTime), endTime(endTime){

}

#endif // !_EVENT_

