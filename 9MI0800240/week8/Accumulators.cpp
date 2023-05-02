#include "Accumulators.h"
#include <cstring>
#include <stdexcept>

void Accumulators::copyFrom(const Accumulators& other)
{
    if (other._accumulatorsId == nullptr)
    {
        throw std::invalid_argument("Trying to create car with null battery id");
    }

    this->_accumulatorsId = new char[strlen(other._accumulatorsId) + 1];
    strcpy(this->_accumulatorsId, other._accumulatorsId);

    if (_ampHours < 0)
    {
        throw std::invalid_argument("Trying to create car battery with invalid amp hours");
    }
    this->_ampHours = other._ampHours;

}

void Accumulators::free()
{
    delete[] _accumulatorsId;
}

Accumulators::Accumulators(const char* identifier, const char* manufacturerName, const char* description,
    const char* accumulatorsId, int ampHours) : CarPart::CarPart(identifier, manufacturerName, description)
{
    if (accumulatorsId == nullptr)
    {
        throw std::invalid_argument("Trying to create car with null battery id");
    }

    this->_accumulatorsId = new char[strlen(accumulatorsId) + 1];
    strcpy(this->_accumulatorsId, accumulatorsId);

    if (_ampHours < 0)
    {
        throw std::invalid_argument("Trying to create car battery with invalid amp hours");
    }
    this->_ampHours = ampHours;

}

Accumulators::Accumulators(const Accumulators& other) : CarPart(other)
{
    copyFrom(other);
}

const Accumulators& Accumulators::operator=(const Accumulators& other)
{
    if (this != &other)
    {
        CarPart::operator=(other);

        free();
        copyFrom(other);
    }

    return *this;
}

Accumulators::~Accumulators()
{
    free();
}

std::ostream& operator<<(std::ostream& os, const Accumulators& battery)
{
    os << static_cast<const CarPart&>(battery) << battery._accumulatorsId << battery._ampHours << std::endl;

    return os;
}
