#include "Time.h"
#include <iostream>

void printTimeFromInt(size_t fromn) {
	std::cout << fromn % 60 << " ";
	fromn /= 60;
	std::cout << fromn % 60 << " ";
	fromn /= 60;
	std::cout << fromn % 60 << " ";
}

void Time::convertToTime(size_t fromn) {
	seconds = fromn % 60;
	fromn /= 60;
	minutes = fromn % 60;
	fromn /= 60;
	hours = fromn % 60;
}

Time::Time(size_t h, size_t m, size_t s) {
	hours = h;
	minutes = m;
	seconds = s;
}

Time::Time(): Time(0, 0, 0){}

Time::Time(size_t fromn) {
	this->convertToTime(fromn);
}

int Time::convertToInt() const{
	return 3600 * hours + 60 * minutes + seconds;
}

int Time::getHours() const{
	return hours;
}
int Time::getMinutes() const{
	return minutes;
}
int Time::getSeconds() const{
	return seconds;
}

bool Time::compare(const Time& other) const{
	return this->convertToInt() < other.convertToInt();
}

int Time::midnight() const {
	return (3600 * 24) - convertToInt();
}

