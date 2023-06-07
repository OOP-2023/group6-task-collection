#include <iostream>
#include <stdexcept>
class Time
{
public:

    Time()
    {
        this->hours = 0;
        this->minutes = 0;
        this->seconds = 0;
    }

    Time(const size_t hours, const size_t minutes, const size_t seconds)
    {
        if(!valid_hours(hours) || !valid_secs_mins(minutes) || !valid_secs_mins(seconds))
            throw std::invalid_argument("Invalid input!");

        this->hours = hours;
        this->minutes = minutes;
        this->seconds = seconds;
    }

    Time(const size_t time_elapsed)
    {
        if(time_elapsed < 0 || time_elapsed > 86399) // Max elapsed time 23:59:59
            throw std::invalid_argument("Invalid input!");

        this->hours = time_elapsed / 3600;
        this->minutes = (time_elapsed % 3600) / 60;
        this->seconds = time_elapsed % 60;
    }

    Time(const Time& to_copy)
    {
        this->hours = to_copy.hours;
        this->minutes = to_copy.minutes;
        this->seconds = to_copy.seconds;
    }

    Time& operator= (const Time& rhs)
    {
        this->hours = rhs.hours;
        this->minutes = rhs.minutes;
        this->seconds = rhs.seconds;
    }

    size_t get_hours() const
    {
        return this->hours;
    }

    size_t get_minutes() const
    {
        return this->minutes;
    }

    size_t get_seconds() const
    {
        return this->seconds;
    }

    size_t set_hours(size_t input)
    {
        if (input < 0 || input > 23)
            throw std::invalid_argument("Invalid hour input!");

        this->hours = input;
    }

    size_t set_minutes(size_t input)
    {
        if (input < 0 || input > 59)
            throw std::invalid_argument("Invalid hour input!");

        this->minutes = input;
    }

    size_t set_seconds(size_t input)
    {
        if (input < 0 || input > 59)
            throw std::invalid_argument("Invalid hour input!");

        this->seconds = input;
    }

    size_t get_time_in_secs() const
    {
        return this->hours * 3600 + this->minutes * 60 + this->seconds;
    }

    size_t compare_time(const Time& other) const
    {
        return other.get_time_in_secs() > this->get_time_in_secs();
    }

    Time time_to_midnight() const
    {
        return Time(86400 - get_time_in_secs());
    }

private:
    size_t hours;
    size_t minutes;
    size_t seconds;

    bool valid_hours(size_t input)
    {
        return input >= 0 && input <= 23;
    }
    
    bool valid_secs_mins(size_t input)
    {
        return input >= 0 && input <= 23;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
