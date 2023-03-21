// Task1Week4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

class Time {

	unsigned hours;
	unsigned min;
	unsigned sec;

	bool isSmallerThanMax(unsigned maxValue, unsigned value) {
		return value <= maxValue;
	}
public:
	Time(unsigned hours, unsigned min, unsigned sec) {
		setHours(hours);
		setMinutes(min);
		setSeconds(sec);
	}
	Time() :Time(0, 0, 0){}

	Time(size_t secondsAfterMidnight) {
		if (!isSmallerThanMax(24 * 3600, secondsAfterMidnight)) {
			secondsAfterMidnight = 0;
		}

		setHours(secondsAfterMidnight / 3600);
		secondsAfterMidnight %= 3600;
		setMinutes(secondsAfterMidnight / 60);
		secondsAfterMidnight %= 60;
		setSeconds(secondsAfterMidnight);
	}

	void setHours(unsigned hours) {
		if (isSmallerThanMax(23, hours)){
			this->hours=hours;
		}
		else {
			this->hours=0;
		}
	}

	void setMinutes(unsigned min) {
		if (isSmallerThanMax(59, min)) {
			this->min = min;
		}
		else {
			this->min = 0;
		}
	}

	void setSeconds(unsigned sec) {
		if (isSmallerThanMax(59, sec)) {
			this->sec = sec;
		}
		else {
			this->sec = 0;
		}
	}

	unsigned getHours()const {
		return hours;
	}
	unsigned getMinutes() const {
		return min;
	}
	unsigned getSeconds() const {
		return sec;
	}

	unsigned getSecondsFromMidnight() const{
		return hours * 3600 + min * 60 + sec;
	}

	void print() const {
		cout << hours << ":" << min << ":" << sec << endl;
	}
};

/*bool compareTime(const Time& other, const Time& timeNow) {
	int otherSeconds = other.getSecondsFromMidnight();
	int timeNow = timeNow.getSecondsFromMidnight();
	
	
}
*/

int main()
{
	Time timeNow(12, 41, 55);

	timeNow.print();
}
