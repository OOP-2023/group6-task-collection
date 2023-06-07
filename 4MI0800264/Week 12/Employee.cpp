#include "Employee.h"

Employee::Employee(std::string inputName, int inputAge, int inputSalary)
{
	name = inputName;
	age = inputAge;
	salary = inputSalary;
}

std::string Employee::getName() const
{
	return name;
}

int Employee::getAge() const
{
	return age;
}

int Employee::getSalary() const
{
	return salary;
}