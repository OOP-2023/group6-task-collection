#pragma once
#include <iostream>

class Employee
{
	std::string name;
	int age;
	int salary;

public:
	
	Employee(std::string inputName, int inputAge, int inputSalary);

	virtual ~Employee() = default;

	std::string getName() const;
	int getAge() const;
	int getSalary() const;

	virtual Employee* clone() = 0;
};