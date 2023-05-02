#ifndef ENGINE_HPP
#define ENGINE_HPP

#include "CarPart.h"

class Engine : public CarPart
{
private:
    int _horsepower;

public:
    friend std::ostream& operator<<(std::ostream&, const Engine&);
    Engine(const char*, const char*, const char* , int);

};


#endif 