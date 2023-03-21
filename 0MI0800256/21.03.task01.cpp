#include <iostream>
using namespace std;

class Time
{
private:
        unsigned int hours;
        unsigned int minutes;
        unsigned int seconds;
        bool isInInterval(unsigned upperInterval, unsigned value)
	{
		return value <= upperInterval;
    }

public:
        Time();
        ~Time();
        Time(unsigned hours, unsigned minutes, unsigned seconds)
	{
		setHours(hours);
		setMinutes(minutes);
		setSeconds(seconds);
    }
        Time(unsigned int n)
	{
		if (!isInInterval(24 * 3600, n))
			n = 0;

		setHours(n / 3600);
		n %= 3600;

		setMinutes(n / 60);
		n %= 60;

		setSeconds(n);
	}
        void setHours(unsigned hours)
	{
		if (isInInterval(23, hours))
			this->hours = hours;
		else
			this->hours = 0;
	}
	void setMinutes(unsigned minutes)
	{
		if (isInInterval(59, minutes))
			this->minutes = minutes;
		else
			this->minutes = 0;
	}
	void setSeconds(unsigned seconds)
	{
		if (isInInterval(59, seconds))
			this->seconds = seconds;
		else
			this->seconds = 0;
	}
	unsigned getHours() const
	{
		return hours;
	}
	unsigned getMinutes() const
	{
		return minutes;
	}
	unsigned getSeconds() const
	{
		return seconds;
	}

};

int main()
{
 
}
