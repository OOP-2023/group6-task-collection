#pragma once
#include "Employee.h"

class Trainee : public Employee
{
	int weeksLeftOfInternship;

public:

	Trainee(const Employee& employee, int inputWeeksLeftOfInternship);

	Trainee(std::string inputName, int inputAge, int inputSalary, int inputWeeksLeftOfInternship);

	Employee* clone() override;
};