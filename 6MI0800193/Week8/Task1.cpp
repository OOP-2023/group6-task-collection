#include <iostream>
#include "CarPart.hpp"
#include "Tire.hpp"
#include "Battery.hpp"
#include "Engine.hpp"
int main()
{
    CarPart part("123", "Ford", "Door1");
    Tire tire1(200, 50, 20, "666", "Michelin", "Pilot 4");
    Battery batery(60, "MaxSpeed", "92", "Varta", "Car_Battery");
    Engine engine(600, "V12662SF", "Ferrari", "V12 Superfast");

    std::cout << part << std::endl;
    std::cout << tire1 << std::endl;
    std::cout << batery << std::endl;
    std::cout << engine << std::endl;
}
