#include <iostream>
#include "Employee.hpp"

int main()
{
    Company* company = new Company();
    company->capacity = 10;
    company->addTrainee("Trainee1", 18, 1000, 10);
    company->addTrainee("Trainee2", 18, 2000, 20);
    company->addTrainee("Trainee3", 18, 3000, 30);
    company->addWorker("MrWorker", 20, 20000, 24);
    company->addWorkingTrainee("Trainee1", 18, 1000, 10, 123);
    company->print();
}