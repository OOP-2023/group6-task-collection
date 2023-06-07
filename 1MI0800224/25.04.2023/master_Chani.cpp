#include <iostream>

class CarPart{
private:
    char* identificator;
    char* name_hersteller;
    char* description;

    void free(){
        delete [] identificator;
        delete [] name_hersteller;
        delete [] description;
    }

    void copyFrom(other){
        this->identificator=new char[strlen(other.identificator)+1];
        strcpy(this->identificator, other.identificator);

        this->name_hersteller=new char[strlen(other.name_hersteller)+1];
        strcpy(this->name_hersteller, other.name_hersteller);

        this->description=new char[strlen(other.description)+1];
        strcpy(this->description, other.description);
    }

public:
    //void operator<<() const;

    //constructor
    CarPart(char const* id, char const* producer, char const* desc){
        this->identificator=new char[strlen(id)+1];
        strcpy(identificator, id);

        this->name_hersteller=new char[strlen(producer)+1];
        strcpy(name_hersteller, producer);

        this->description=new char[strlen(desc)+1];
        strcpy(description, desc);
    }
    //destructor
    ~CarPart(){
        free();
    }
    //copy constructor
    CarPart(CarPart const& other){
        copyFrom(other);
    }
    //operator=
    CarPart& operator=(CarPartt const& other){
        if(this!=&other){
            free();
            copyFrom(other);
        }
        return *this;
    }
    //move constructor
    CarPart(CarPart && other){
        this->identificator=other.identificator;
        this->name_hersteller=other.name_hersteller;
        this->description=other.description;

        other.identificator=nullptr;
        other.name_hersteller=nullptr;
        other.description=nullptr;
    }
    //move operator=
    CarPart& (CarPart && other){
        if(this!=&other){
            free();
            this->identificator=other.identificator;
            this->name_hersteller=other.name_hersteller;
            this->description=other.description;

            other.identificator=nullptr;
            other.name_hersteller=nullptr;
            other.description=nullptr;
        }
        return *this;
    }
};
