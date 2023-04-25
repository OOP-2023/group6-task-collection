#include <iostream>
#include <fstream>
#include<cstring>
#pragma warning (disable:4996)
using namespace std;

class CarPart {
private:
    char* id;
    char* name;
    char* description;
    void free();
    void copy(const char* source, char* target);
public:
    CarPart(CarPart& other);
    CarPart& operator=(CarPart& other);
    CarPart(const char* id, const char* name, const char* description);
    ~CarPart();
};
void CarPart::free() {
    delete[] id;
    delete[] name;
    delete[] description;
}
void CarPart::copy(const char* source, char* target) {
    target = new char[strlen(source)+1];
    strcpy(target, source);
}
CarPart::CarPart(CarPart& other) {
    copy(other.id, id);
    copy(other.name, name);
    copy(other.description, description);
}
CarPart& CarPart::operator=(CarPart& other) {
    if (this != &other)
    {
        free();
        copy(other.id, id);
        copy(other.name, name);
        copy(other.description, description);
    }
    return *this;
}
CarPart::CarPart(const char* id, const char* name, const char* description) {
    copy(id, this->id);
    copy(name, this->name);
    copy(description, this->description);
}
CarPart::~CarPart() {
    free();
}

class Tyre :CarPart{
private:
    int width;//155-365
    int profile;//30-80
    int diameter;//13-21
public:
    Tyre(const char* id, const char* name, const char* description,const int width, const int profile, const int diameter);
    const int getWidth()const;
    void setWidth(const int& other);
    const int getProfile()const;
    void setProfile(const int& other);
    const int getDiameter()const;
    void setDiameter(const int& other);
};
Tyre::Tyre(const char* id, const char* name, const char* description,const int width, const int profile, const int diameter)
    :CarPart(id, name, description) {
    setWidth(width);
    setProfile(profile);
    setDiameter(diameter);
}
const int Tyre::getWidth()const {
    return width;
}
void Tyre::setWidth(const int& other) {
    if (other< 155 && other>365)
        throw "Error";

    width = other;
}
const int Tyre::getProfile()const {
    return profile;
}
void Tyre::setProfile(const int& other) {
    if (other < 30 && other>80)
        throw "Error";

    profile = other;
}
const int Tyre::getDiameter()const {
    return diameter;
}
void Tyre::setDiameter(const int& other) {
    if (other < 13 && other>21)
        throw "Error";

    diameter = other;
}
class Engine :CarPart{
private:
    unsigned int horsepower;
public:
    Engine(const char* id, const char* name, const char* description,unsigned int _horsepower);
    const unsigned int getHorsepower() const;
    void setHorsepower(const unsigned int other);
};
Engine::Engine(const char* id, const char* name, const char* description,unsigned int _horsepower):CarPart(id, name, description) {
    horsepower = _horsepower;
}
const unsigned int Engine::getHorsepower() const {
    return horsepower;
}
void Engine::setHorsepower(const unsigned int other) {
    horsepower = other;
}

class Accumulator :CarPart{
private:
    unsigned int capacity;
    char* batteryId;
    void free();
    void copy(const char* source, char* target);

public:
    Accumulator(const char* id, const char* name, const char* description, Accumulator& other);
    Accumulator(const char* id, const char* name, const char* description, const unsigned int capacity, const char* batteryId);
    Accumulator& operator=(Accumulator& other);
    ~Accumulator();
 };
void Accumulator::free() {
    delete[] batteryId;
}
void Accumulator::copy(const char* source, char* target) {
    target = new char[strlen(source) + 1];
    strcpy(target, source);
}
Accumulator::Accumulator(const char* id, const char* name, const char* description, Accumulator& other):CarPart(id, name, description) {

}
Accumulator::Accumulator(const char* id, const char* name, const char* description, const unsigned int capacity, const char* batteryId):CarPart(id, name, description) {

}
Accumulator& Accumulator::operator=(Accumulator& other) {

}
Accumulator::~Accumulator() {

}
int main()
{
    
}
