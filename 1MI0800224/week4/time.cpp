#include <iostream>
using namespace std;

class Time{
private:
    unsigned short hours;
    unsigned short minutes;
    unsigned short seconds;

public:
   // Time(unsigned short hours=0, unsigned short minutes=0, unsigned short seconds=0); // constructor 1
    Time(unsigned short stunden, unsigned short mins, unsigned short secs); // constructor 2
    Time(size_t Sekunden); // constructor 3
    size_t getHours() const;
    size_t getMinutes() const;
    size_t getSeconds() const;
    void setHours(const unsigned short& Stunden);
    void setMinutes(const unsigned short& Minuten);
    void setSeconds(const unsigned short& Sekunden);
    bool compareTime(const Time& other);
};

//definition of constructor 2
Time::Time(unsigned short stunden, unsigned short mins, unsigned short secs){
    this->seconds=secs;
    this->minutes=mins;
    this->hours=stunden;
}

//definition of constructor 3
Time::Time(size_t Sekunden){
    Sekunden = this->hours*3600 + this->minutes*60 + this->seconds;
    this->seconds = Sekunden;
}

size_t Time::getHours()const{
    return hours;
}
size_t Time::getMinutes()const{
    return minutes;
}

size_t Time::getSeconds()const{
    return seconds;
}

void Time::setHours(const unsigned short& Stunden){
    this->hours = Stunden;
}

void Time::setMinutes(const unsigned short& Minuten){
    this->minutes = Minuten;
}

void Time::setSeconds(const unsigned short& Sekunden){
    this->seconds = Sekunden;
}

size_t TimeToSeconds(const Time& obj){
        return obj.getHours()*3600+obj.getMinutes()*60+obj.getSeconds();
    }

bool Time::compareTime(const Time& other){
    return TimeToSeconds(other)>TimeToSeconds(*this);
}

int main(){
}
