#include <iostream>

class Time
{
private:
	unsigned int hours = 0;
	unsigned int min = 0;
	unsigned int sec = 0;
	bool isValidValue(unsigned int upper, unsigned int value)
	{
		return value <= upper;
	}
public:
	Time(Time hours, Time min, Time sec);
	Time(size_t seconds);
	Time();
	~Time();
	unsigned int getHours()const;
	unsigned int getMin()const;
	unsigned int getSec()const;
	void setHours();
	void setMin();
	void setSec();
	Time(unsigned int hours, unsigned int min, unsigned int sec) {
		setHours(hours);
		setMin(min);
		setSec(sec);
	}

	Time(size_t n)
	{
		if (!isValidValue(24 * 36, n))
			n = 0;
		setHours(n / 3600);
		n %= 3600;
		setMin(n / 60);
		n %= 60;
		setSec(n);
	}
	~Time()
	{
	}
unsigned int getHours()const
{
	return hours;
}
unsigned int getMin()const
{
	return min;
}
unsigned int getSec()const
{
	return sec;
}
void setHours(unsigned int hours)
{
	if (isValidValue(23, hours))
	{
		this->hours = hours;
	}
	else
		this-> hours = 0;
}
void setMin(unsigned int min)
{
	if (isValidValue(59, min))
	{
		this->min = min;
	}
	else
		this->min = 0;
}
void setSec(unsigned int sec)
{
	if (isValidValue(59, sec))
	{
		this->sec = sec;
	}
	else
		this->sec = 0;
}
};

int main()
{
	
}
