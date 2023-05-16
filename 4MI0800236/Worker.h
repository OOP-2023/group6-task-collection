#pragma once
#include <vector>
#include "Employee.h"

class Worker :public Employee {
protected:
	int monthsWorked;
	std::vector<size_t> projectIndex;

public:
	Worker(std::string name, int age, double salary, int monthsWorked, std::vector<size_t> projectIndex);

	virtual double getSalary() const override;

	int getMonthsWorked() const;

	std::vector<size_t> getProjectIndex() const;

};
