#ifndef ACCUMULATORS_HPP
#define ACCUMULATORS_HPP

#include "CarPart.h"

class Accumulators : public CarPart
{
private:
    int _ampHours;
    char* _accumulatorsId;

    void copyFrom(const Accumulators& other);
    void free();


public:
    Accumulators(const char* id, const char* manufacturer, const char* description,
        const char* battery_id, int amp_hours);

    friend std::ostream& operator<<(std::ostream& os, const Accumulators& battery);
   
    Accumulators(const Accumulators& other);
    const Accumulators& operator=(const Accumulators& other);
    ~Accumulators();
};


#endif

