// 21_03.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Time
{
    unsigned hours;
    unsigned minutes;
    unsigned seconds;

    bool isValidValue(unsigned upper, unsigned value)
    {
        return value <= upper;
    }

public:
    Time(unsigned hours, unsigned minutes, unsigned seconds) : hours(0), minutes(0), seconds(0)
    {
        setHours(hours);
        setMinutes(minutes);
        setSeconds(seconds);
    }

    Time(unsigned secondsТоMidnight)
    {
        if (!isValidValue(24*3600, secondsТоMidnight))
        {
            secondsТоMidnight = 0;
        }

        setHours(secondsТоMidnight/3600);
        secondsТоMidnight %= 3600;

        setMinutes(secondsТоMidnight/60);
        secondsТоMidnight %= 60;

        setSeconds(secondsТоMidnight);
    }

    void setHours(unsigned hours)
    {
        if (isValidValue(23, hours))
        {
            this->hours = hours;
        }
        else
            this->hours = 0;
    }

    void setMinutes(unsigned minutes)
    {

        if (isValidValue(59, minutes))
        {
            this->minutes = minutes;
        }
        else
            this->minutes = 0;
    }
    void setSeconds(unsigned seconds)
    {
        if (isValidValue(59, seconds))
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

    unsigned getsecondsToMidnight() const
    {
        return hours * 3600 + minutes * 60 + seconds;
    }


    void print() const
    {
        std::cout << hours << " : " << minutes << " : " << seconds<< std::endl;
    }
};

int compareTimes(const Time& lhs, const Time& rhs)
{
    int lhsSeconds = lhs.getsecondsToMidnight();
    int rhsSeconds = rhs.getsecondsToMidnight();
    return lhsSeconds - rhsSeconds;
}

Time diff(const Time& lhs, const Time& rhs)
{
    int diff = lhs.getsecondsToMidnight() - rhs.getsecondsToMidnight();
    unsigned diffInSeconds = abs(diff);
    return Time(diffInSeconds);
}

int main()
{
    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
