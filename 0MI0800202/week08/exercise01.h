#ifndef WEEK08_EXERCISE01_H
#define WEEK08_EXERCISE01_H

#include <iostream>

class CarPart
{
private:
    char* identificator;
    char* manufacturer;
    char* description;
public:
    CarPart(const char* identificator, const char* manufacturer, const char* description);
    char* idGetter() const;
    char* manufacturerGetter() const;
    char* descGetter() const;
};
class Engine : CarPart
{
private:
    int horsePower;
public:
    friend std::ostream& operator<<(std::ostream& os, const Engine& part);
};

class Wheel : CarPart
{
private:
    int width;
    int profil;
    int diameter;
public:
    friend std::ostream& operator<<(std::ostream& os, const Wheel& part);

};
class Battery : CarPart
{
    int capacity;
    char* batteryId;
public:
    friend std::ostream& operator<<(std::ostream& os, const Battery& part);
};


#endif //WEEK08_EXERCISE01_H
