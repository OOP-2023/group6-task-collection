#include <iostream>

class Time
{
private:
	unsigned hours;
	unsigned mins;
	unsigned secs;

	bool isNotInterval(unsigned number, unsigned upperLimit)
	{
		return number < 0 || number > upperLimit;
	}
	unsigned transitionToSecs(const Time& time)
	{
		return time.hours * 3600 + time.mins * 60 + time.secs;
	}

public:
	Time(unsigned _hours = 0, unsigned _mins = 0, unsigned _secs = 0)
	{
		setHours(_hours);
		setMins(_mins);
		setSecs(_secs);
	}
	Time(size_t secsFromMidnight)
	{
		setHours(secsFromMidnight / 3600);
		secsFromMidnight %= 3600;
		setMins(secsFromMidnight / 60);
		setSecs(secsFromMidnight % 60);
	}
	unsigned getHours()
	{
		return hours;
	}
	unsigned getMins()
	{
		return mins;
	}
	unsigned getSecs()
	{
		return secs;
	}
	void setHours(unsigned _hours)
	{
		if (isNotInterval(_hours, 24))
		{
			hours = 0;
		}
		else hours = _hours;
	}
	void setMins(unsigned _mins)
	{
		if (isNotInterval(_mins, 61))
		{
			mins = 0;
		}
		else mins = _mins;
	}
	void setSecs(unsigned _secs)
	{
		if (isNotInterval(_secs, 61))
		{
			secs = 0;
		}
		else secs = _secs;
	}
	bool compareTimes(const Time& other)
	{
		return transitionToSecs(other) <= transitionToSecs(*this);
	}
	void timeLeftTillMidnight()
	{
		Time timeLeft;
		timeLeft.setHours(23 - hours);
		timeLeft.setMins(59 - mins);
		timeLeft.setSecs(60 - secs);

		timeLeft.print(std::cout);
	}
	void print(std::ostream& out) const
	{
		out << hours << ":" << mins << ":" << secs << std::endl;
	}

};

int main()
{
	Time time(15, 32, 15);
	Time otherTime(16, 39, 50);
	Time otherTime2(13, 44, 69);
	time.print(std::cout);
	otherTime2.print(std::cout);
	time.timeLeftTillMidnight();
	std::cout << time.compareTimes(otherTime) << std::endl;
	std::cout << time.compareTimes(otherTime2) << std::endl;
}
