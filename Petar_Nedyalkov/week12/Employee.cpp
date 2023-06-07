#include <iostream>
#include "Employees.hpp"

Employee::Employee() : Employee("",0,0) {

}

Employee::Employee(const std::string& arg, size_t _age, size_t _salary)
{
	name = arg;
	age = _age;
	salary = _salary;
}

std::string Employee::getName() const {
	return name;
}

size_t Employee::getAge() const {
	return age;
}

size_t Employee::getSalary() const {
	return salary;
}
