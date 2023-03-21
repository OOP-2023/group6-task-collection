#include <iostream> 

class Time {
private:
    size_t hours;
    size_t minutes;
    size_t seconds;
public:
    size_t getHours() const;
    void setHours(const size_t hours);
    size_t getMinutes() const;
    // encapsulation
    void setMinutes(const size_t minutes) {
        this->minutes = minutes;
    }
    size_t getSeconds() const;
    void setSeconds(const size_t seconds);

    Time();
    Time(const size_t hours, const size_t minutes, const size_t seconds);
    Time(const size_t time);
};

Time::Time(const size_t time) {
    size_t n = time;
    hours = n / 3600;
    n %= 3600;
    minutes = n / 60;
    n %= 60;
    seconds = n;
}

Time::Time(const size_t hours, const size_t minutes, const size_t seconds) {
    this->hours = hours;
    this->minutes = minutes;
    this->seconds = seconds;
}

Time::Time(): Time(0, 0, 0) {}

int main() {
    Time t;
    t.setMinutes(100);
}