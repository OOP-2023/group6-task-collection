#pragma once
#include <vector>
#include "Employee.h"

class Worker : public Employee
{
	int monthsWorked;
	std::vector<size_t> projectsIndexes;

public:
	Worker(const Employee& employee, int inputMonthsWorked, std::vector<size_t> inputProjectsIndexes);

	Worker(std::string inputName, int inputAge, int inputSalary, int inputMonthsWorked, std::vector<size_t> inputProjectsIndexes);
	
	Employee* clone() override;
};