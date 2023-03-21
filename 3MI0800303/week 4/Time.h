#ifndef _TIME_HPP
#define _TIME_HPP

class Time {
private:
    size_t hours;
    size_t minutes;
    size_t seconds;
    int convertToInt() const;
    void convertToTime(size_t);

public:
    Time();
    Time(size_t h, size_t m, size_t s);
    Time(size_t);
    int getHours() const;
    int getMinutes() const;
    int getSeconds() const;
    bool compare(const Time& other) const;
    int midnight() const;
};

#endif