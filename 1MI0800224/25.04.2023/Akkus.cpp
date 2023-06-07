#include <iostream>

class Akku: public CarPart{
private:
    int capacity;
    char* battery_id;
public:
    //constructor
    Akku(char const* id, char const* producer, char* descr, int cap, char* bat): CarPart(id, producer, descr){
        this->capacity=cap;
        this->battery_id=new char[strlen(bat)+1];
        strcpy(battery_id, bat);
    }
    //destructor
    ~Akku(){
        delete [] battery_id;
    }
    //copy constructor
    Akku(Akku const& other): CarPart(other){
        this->capacity=other.capacity;
        this->battery_id=new char[strlen(other.id)+1];
        strcpy(battery_id, bat);
    }

    //operator=
    Akku& (Akku const& other){
        if(this!=&other){
            CarPart::operator=(other);
            delete [] battery_id;
            this->capacity=other.capacity;
            this->battery_id=new char[strlen(other.id)+1];
            strcpy(battery_id, bat);
        }
        return *this;
    }
};
