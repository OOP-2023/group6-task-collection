#include <cstring>
#include "exercise01.h"


CarPart::CarPart(const char *_identificator, const char *_manufacturer, const char *_description)
{
    identificator = new char[strlen(_identificator)];
    manufacturer = new char[strlen(_manufacturer)];
    description = new char[strlen(_description)];
    strcpy(identificator, _identificator);
    strcpy(manufacturer, _manufacturer);
    strcpy(description, _description);
}

char *CarPart::idGetter() const
{
    return identificator;
}

char *CarPart::manufacturerGetter() const
{
    return manufacturer;
}

char *CarPart::descGetter() const
{
    return description;
}

std::ostream &operator<<(std::ostream &os, const Engine &part)
{
    os << part.idGetter() << " by " << part.manufacturerGetter() << " - " << part.descGetter() << " - " << part.horsePower << "hp";
    return os;
}

std::ostream &operator<<(std::ostream &os, const Wheel &part)
{
    os << part.idGetter() << " by " << part.manufacturerGetter() << " - " << part.descGetter() << " - " << part.width << '/' << part.profil << 'R' << part.diameter;
    return os;
}

std::ostream &operator<<(std::ostream &os, const Battery &part)
{
    os << part.idGetter() << " by " << part.manufacturerGetter() << " - " << part.descGetter() << " - " << part.capacity << "Ah";
    return os;
}

class FuelTank()
{

}