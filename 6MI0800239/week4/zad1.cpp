#include <iostream>
using namespace std;

class Time
{
    unsigned hours;
    unsigned minutes;
    unsigned seconds;

    bool isInInterval(unsigned upperInterval, unsigned value)
    {
        return value <= upperInterval;
    }

public:

    Time(unsigned hours, unsigned minutes, unsigned seconds)
    {
        setHours(hours);
        setMinutes(minutes);
        setSeconds(seconds);
    }

    Time() : Time(0, 0, 0)
    {}

    Time(size_t midnight)
    {
        if (!isInInterval(24*3600,midnight))
        {
            midnight = 0;
        }

        setHours(midnight / 3600);
        midnight %= 3600;

        setMinutes(midnight / 60);
        midnight %= 60;

        setSeconds(midnight);
    }
    
    void setHours(unsigned hours)
    {
        if (isInInterval(23, hours))
        {
            this->hours = hours;
        }
        else
            this->hours = 0;
    }

    void setMinutes(unsigned minutes)
    {
        if (isInInterval(59, minutes))
        {
            this->minutes = minutes;
        }
        else
            this->minutes = 0;
    }

    void setSeconds(unsigned second)
    {
        if (isInInterval(59, seconds))
        {
            this->seconds = seconds;
        }
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

    unsigned secondsToMid() const
    {
        return hours * 3600 + minutes * 60 + seconds;
    }

    void print() const
    {
        cout << hours << ':' << minutes << ':' << seconds;
    }
};

bool compareTime(const Time& other, const Time& rightNow)
{
    int otherInSec = other.secondsToMid();
    int rightNowInSec = rightNow.secondsToMid();
    return otherInSec > rightNowInSec;
}

//int main()
//{
//    
//
//}


