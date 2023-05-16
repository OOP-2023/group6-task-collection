#pragma once
#include "Worker.h"
#include "Trainee.h"

class WorkingIntern : public Worker, public Trainee
{
private:
	size_t _dayOfInternship = 0;
public:
	WorkingIntern(std::string name, size_t age, size_t salary,
		size_t monthsOfWork, std::vector<size_t>  project, size_t weekToEndOfInternship, size_t dayOfInternship) :
		Employee(name, age, salary),
		Worker(name, age, salary,monthsOfWork, project),
		Trainee(name, age, salary,weekToEndOfInternship)
	{
		_dayOfInternship = dayOfInternship;
	}

	Employee* clone() const override
	{
		return new WorkingIntern(*this);
	}

	~WorkingIntern() = default;

};

/*
		Employee
		/		\
	worker		trainee
		\		/
		AdvancedWorker

*/