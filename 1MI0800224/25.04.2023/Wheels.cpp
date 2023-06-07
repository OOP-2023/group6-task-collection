#include <iostream>

class Wheel: public CarPart{
private:
    unsigned shirina;
    unsigned profil;
    unsigned tsol;

    unsigned AssertValue(unsigned minim, unsigned maxim, unsigned value){
        if(width<minim || widht>maxim)
            throw std::exception("Not in range.");
        retrun value;
    }

public:
    //constructor
    Wheel(char const* id, char const* hersteller, char const* description, unsigned shirina, unsigned profil, unsigned diam): CarPart(id, hersteller, description){
        this->shirina=AssertValue(155, 365, shirina);
        this->profil=AssertValue(30, 80, profil);
        this->tsol=AssertValue(13, 21, diam);
    }

};
