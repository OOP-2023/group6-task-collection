#pragma once
#include "Employee.h"
#include <vector>

class Worker : public virtual Employee
{
private:
	size_t _monthsOfWork = 0;
	std::vector<size_t>  _project;
public:
	Worker(std::string name, size_t age, size_t salary,
		size_t monthsOfWork, std::vector<size_t>  project) : Employee(name,age,salary)
	{

		_monthsOfWork = monthsOfWork;
		_project = project;
	}
	Employee* clone() const override
	{
		return new Worker(*this);
	}

	~Worker() = default;
};

