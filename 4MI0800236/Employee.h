#pragma once
#include <string>

class Employee {
protected: 
	std::string name;
	int age;
	double salary;

public:
	Employee( std::string& name, int age, double salary);

	virtual ~Employee(){}

	virtual double getSalary() const;

	virtual std::string getName() const;
};
