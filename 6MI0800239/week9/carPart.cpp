#include <iostream>
#include <cstring>
#pragma warning (dissable:4996)
using namespace std;

class CarPart {
protected:
    unsigned identificator;
    char* name;
    char* description;


public:
    CarPart(unsigned _id,char* _name,char* _desc):identificator(_id) {
        strcpy(name,_name);
        strcpy(description, _desc);
    }

    virtual CarPart* clone() const 
    {
        return new CarPart(*this);
    }

    virtual ~CarPart() {}

    friend std::ostream& operator<<(std::ostream& os, const CarPart& part)
    {
        os << "(" << part.identificator << ") by" << part.name << " _ " << part.description;
        return os;
    }
};

class Tyres: public CarPart {
    unsigned shirochina;
    unsigned profile;
    unsigned diam;
public:
    Tyres(unsigned _id, char* _name, char* _desc,unsigned _shirochina,unsigned _profile,unsigned _diam):CarPart(_id, _name, _desc),
        shirochina(_shirochina), profile(_profile), diam(_diam) {}

    Tyres* clone() const override
    {
        return new Tyres(*this);
    }


    friend std::ostream& operator<<(std::ostream& os, const Tyres& tyre)
    {
        os << static_cast<const CarPart&>(tyre) << " - " << tyre.shirochina<< " mm"<< tyre.profile<< tyre.diam<< " inch";
    }
    
};

class Engine: public CarPart {
    unsigned hp;
public:
    Engine(unsigned _id, char* _name, char* _desc, unsigned _hp) :CarPart(_id, _name, _desc), hp(_hp) {}

    Engine* clone() const  override
    {
        return new Engine(*this);
    }

    friend std::ostream& operator<<(std::ostream& os, const Engine& engine)
    {
        os << static_cast<const CarPart&>(engine) << " - " << engine.hp << " hp";
    }

    const unsigned getHP()
    {
        return hp;
    }
};

class Akumolator : public CarPart{
    double capacity;
    char* batteryId;
public:
    Akumolator(unsigned _id, char* _name, char* _desc, double _capacity,char* _batteryId) :CarPart(_id, _name, _desc), capacity(_capacity) {
        strcpy(batteryId, _batteryId);
    }

    Akumolator* clone()const override
    {
        return new Akumolator(*this);
    }

    friend std::ostream& operator<<(std::ostream& os, const Akumolator& acum)
    {
        os << static_cast<const CarPart&>(acum) << " - " << acum.capacity << " Ah" << acum.batteryId;
    }
};


class FuelTank: public CarPart{
    double capacity;
    double currentFuel;

public:
    FuelTank(unsigned _id, char* _name, char* _desc, double _capacity) :CarPart(_id, _name, _desc), capacity(_capacity), currentFuel(_capacity) {}

    void use(double toUse)
    {
        if (toUse > currentFuel) {
            throw std::exception("There is not enough fuel");
            currentFuel = 0;
        }
        currentFuel -= toUse;
    }

    void fill(double toFill)
    {
        if (toFill + currentFuel > capacity) {
            throw std::exception("There is not enough space in the tank");
            currentFuel = capacity;
        }
        currentFuel += toFill;
    }

    double getCapacity() const
    {
        return capacity;
    }

    void setCapacity(double _capacity)
    {
        capacity = _capacity;
    }
};


class Car {
    FuelTank tank;
    Engine engine;
    Tyres tyres[4];
    Akumolator acum;
    unsigned km;
    unsigned kg;
public:
    const FuelTank& getFuelTank()
    {
        return tank;
    }
    Car(int tankId,char* tankMan,char* tankDescription,double fuelCapacity,
        int engineId, char* engineManufacturer,char* engineDescription, int horsepower,
        Tyres _tyres[4],
        unsigned Id, char* batteryManufacturer,char* batteryDescription,double ampHours,char* batteryId,
        double mileage, double weight)
        : tank(tankId, tankMan, tankDescription,fuelCapacity),
          engine(engineId, engineManufacturer, engineDescription, horsepower),
          tyres(_tyres),
          acum(Id, batteryManufacturer, batteryDescription, ampHours, batteryId),
          km(mileage), 
          kg(weight) {}

    void drive(double _km)
    {
        if (tank.getCapacity() < _km)
            return;
        km += _km;
        tank.setCapacity(tank.getCapacity() - _km);
    }

    Engine& getEngine() 
    {
        return engine;
    }

    const unsigned getWeight()
    {
        return kg;
    }
};

Car* dragRace(Car* car1, Car* car2)
{
    double distance = 0.4;

    if (car1->getFuelTank().getCapacity() < distance && car2->getFuelTank().getCapacity() < distance)
        return nullptr;

    else if (car1->getFuelTank().getCapacity() < distance)
        return car2;

    else if (car2->getFuelTank().getCapacity() < distance)
        return car1;


    double ratio1 = car1->getWeight() / car1->getEngine().getHP();
    double ratio2 = car2->getWeight() / car2->getEngine().getHP();

    if (ratio1 > ratio2)
        return car1;

    else
        return car2;
}

int main()
{
    
}

