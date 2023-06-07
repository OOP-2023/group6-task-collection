#include <cstring>
#include <iostream>

class CarPart {
    char* identificator;
    char* producer;
    char* description;
public:
    CarPart(const char* id, const char* prod, const char* desc);
    friend std::ostream& operator<<(std::ostream& os, const CarPart& part);
    ~CarPart();
};

CarPart::CarPart(const char* id, const char* prod, const char* desc)
{
    identificator = new char[strlen(id) + 1];
    strcpy(identificator, id);
    producer = new char[strlen(prod) + 1];
    strcpy(producer, prod);
    description = new char[strlen(desc) + 1];
    strcpy(description, desc);
}

std::ostream& operator<<(std::ostream& os, const CarPart& part)
{
    os << "(" << part.identificator << ") by " << part.producer << " - " << part.description;
    return os;
}

CarPart::~CarPart() {
    delete[] identificator;
    delete[] description;
    delete[] producer;
}

class Engine: CarPart {
private:
    unsigned horsepower;
public:
    friend std::ostream& operator<<(std::ostream& os, const Engine& eng);
    Engine(const char* id, const char* prod, const char* desc, unsigned hp);
    ~Engine();
};

std::ostream& operator<<(std::ostream& os, const Engine& eng) {
    os << (const CarPart&)eng;
    os << " - " << eng.horsepower << " hp";
    return os;
}

Engine::Engine(const char* id, const char* prod, const char* desc, unsigned hp): CarPart(id, prod, desc) {
    horsepower = hp;
}

Engine::~Engine() {}

class Tire: CarPart {
    unsigned width;
    unsigned profile;
    unsigned diameter;
};

class Battery: CarPart {
    unsigned capacity;
    char* batteryid;
};

int main() {
    Engine eng("123", "mazda", "trash engine 1.2l", 4);
    std::cout << eng << std::endl;
}
