#pragma once
#include "Employee.h"
#include "Trainee.h"
#include "Worker.h"
#include "WorkingTrainee.h"

class Company
{
	std::vector<Employee*> data;

	void sort();

public:

	Company();

	Company(const Company& other);

	void addWorker(Worker* const worker);

	void addTrainee(Worker* const trainee);

	void addWorkingTrainee(Worker* const workingTrainee);

	double getAverageSalary();
};