#include <iostream>
using namespace std;

class Time
{
private:
	size_t hours;
	size_t mins;
	size_t seconds;
	

	bool isValid(size_t hours, size_t mins, size_t seconds) const
	{
		return hours < 24 && mins < 60 && seconds < 60;
	}

	size_t timeToSeconds(size_t hours, size_t mins, size_t seconds) const
	{
		return (hours * 3600 + mins * 60 + seconds);
	}

public:
	Time()
	{
		hours = 0;
		mins = 0;
		seconds = 0;
	}

	Time(size_t hours, size_t mins, size_t seconds)
	{
		if (!isValid(hours, mins, seconds))
			return;

		this->hours = hours;
		this->mins = mins;
		this->seconds = seconds;
	}

	Time(size_t secondsFromMidnight) //: hours(0), mins(0), seconds(0)
	{
		if (secondsFromMidnight > (24 * 3600))
			return;

		hours = secondsFromMidnight / 3600;
		secondsFromMidnight %= 3600;
		mins = secondsFromMidnight / 60;
		secondsFromMidnight %= 60;
		seconds = secondsFromMidnight;
	}


	size_t getHours()
	{
		return hours;
	}
	void setHours(size_t inputHours)
	{
		if (inputHours > 23)
			return;

		hours = inputHours;
	}

	size_t getMinutes()
	{
		return mins;
	}
	void setMinutes(size_t inputMinutes)
	{
		if (inputMinutes > 59)
			return;

		mins = inputMinutes;
	}

	size_t getSeconds()
	{
		return seconds;
	}
	void setSeconds(size_t inputSeconds)
	{
		if (inputSeconds > 59)
			return;

		seconds = inputSeconds;
	}

	bool compareTimes(const Time& other) const
	{
		return other.timeToSeconds(other.hours, other.mins, other.seconds) >
			this->timeToSeconds(this->hours, this->mins, this->seconds);
	}

	Time timeFromMidnight() const
	{
		Time newTime;

		size_t remainingSeconds = 24 * 3600 - this->timeToSeconds(hours, mins, seconds);
		newTime.hours = remainingSeconds / 3600;
		remainingSeconds %= 3600;
		newTime.mins = remainingSeconds / 60;
		remainingSeconds %= 60;
		newTime.seconds = remainingSeconds;

		return newTime;
	}
};

int main()
{

	return 0;
}