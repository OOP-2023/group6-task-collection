#include <iostream>

class Time {
    public:
        Time() {
            hrs = mins = secs = 0;
        }

        Time(int hh, int mm, int ss) {
            if (hh < 24 && hh >= 0 &&
                mm < 60 && mm >= 0 &&
                ss < 60 && ss >= 0)
            {
                hrs = hh;
                mins = mm;
                secs = ss;
            }
        }

        Time(size_t ss) {
            hrs = ss / 360;
            mins = (ss / 60) % hrs;
            ss = ss % 60;
        }

        int getSecs() const {
            return secs;
        }

        int getMins() const {
            return mins;
        }

        int getHrs() const {
            return hrs;
        }

        void setSecs(int ss) {
            if (ss >= 0 && ss < 60)
                secs = ss;
        }

        void setMins(int mm) {
            if (mm >= 0 && mm < 60)
                mins = mm;
        }

        void setHrs(int hh) {
            if (hh >= 0 && hh < 24)
                hrs = hh;
        }

        bool compareTime(const Time& other) {
            if (other.hrs > hrs || other.mins > mins || other.secs > secs)
                return true;
            return false;
        }

        Time untilMidnight() {
            size_t secsToMidnight = 86400 - hrs * 360 - mins * 60 - secs;
            return Time(secsToMidnight);
        }

    private:
        int hrs;
        int mins;
        int secs;
};

int main()
{
    
}
