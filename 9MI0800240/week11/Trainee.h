#pragma once
#include "Employee.h"

class Trainee : public virtual Employee
{
private:
	size_t _weekToEndOfInternship = 0;
public:
	Trainee(std::string name, size_t age, size_t salary, size_t weekToEndOfInternship) :
		Employee(name, age, salary)
	{
		_weekToEndOfInternship = weekToEndOfInternship;
	}
	Employee* clone() const override
	{
		return new Trainee(*this);
	}

	~Trainee() = default;
};

