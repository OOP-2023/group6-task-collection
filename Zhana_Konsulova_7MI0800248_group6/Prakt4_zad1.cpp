// Prakt_21.03_zad1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int assertInRange(int element, int min, int max) {
    if (element < min || element > max) {
        throw std::invalid_argument("element not in range");
    }

    return element;
}

#define CONST_ZERO 0
#define LAST_HOUR 23
#define LAST_MINUTES_OR_SECONDS 59

class Time {
private:
    size_t hours;
    size_t minutes; 
    size_t seconds;

public:
    Time() : Time(0, 0, 0) {}

    Time(size_t s) : Time(s / 3600, (s % 3600) / 60, (s % 3600) % 60) {}

    Time(size_t h, size_t m, size_t s)
    {
        hours = assertInRange(h, CONST_ZERO, LAST_HOUR);
        minutes = assertInRange(m, CONST_ZERO, LAST_MINUTES_OR_SECONDS);
        seconds = assertInRange(s, CONST_ZERO, LAST_MINUTES_OR_SECONDS);
    }
    
    void printTime()
    {
        if (hours < 10)
            std::cout << "0" << hours;
        else
            std::cout << hours;

        if (minutes < 10)
            std::cout << ":0" << minutes;
        else
            std::cout <<":" << minutes;

        if (seconds < 10)
            std::cout << ":0" << seconds;
        else
            std::cout << ":" << seconds;
    }

    size_t getHours(Time t) {
        return t.hours;
    }
    size_t getMinutes(Time t) {
        return t.minutes;
    }
    size_t getSeconds(Time t) {
        return t.seconds;
    }

    void setHours(Time t, size_t hours)
    {
        t.hours = assertInRange(hours, CONST_ZERO, LAST_HOUR);
    }
    void setMinutes(Time t, size_t minutes)
    {
        t.minutes = assertInRange(minutes, CONST_ZERO, LAST_MINUTES_OR_SECONDS);
    }
    void setSeconds(Time t, size_t seconds)
    {
        t.seconds = assertInRange(hours, CONST_ZERO, LAST_MINUTES_OR_SECONDS);
    }

    Time latestTime(const Time& other);

    Time timeUntilMidnight();
        
};

Time Time::latestTime(const Time& other)
{
    size_t h = getHours(other);
    size_t m = getMinutes(other);
    size_t s = getSeconds(other);

    if (hours < h || (hours == h && minutes < m ||
        (hours == h && minutes == m && seconds < s)))
        return Time(h, m, s);

    else
        return other;
}

Time Time::timeUntilMidnight()
{
    return Time(LAST_HOUR - hours, 59 - minutes, 59 - seconds);
}



int main()
{
    Time t(12, 59, 0);
    t.printTime();
    std::cout<<endl;

    Time newT;
    newT = t.timeUntilMidnight();
    newT.printTime();
}


