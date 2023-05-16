#pragma once
#include "Employee.h"

class Trainee : public Employee{
protected: 
	int weeksLeft;

public:
	Trainee(std::string name, int age, double salary, int weeksLeft);

	virtual double getSalary() const override;

}
