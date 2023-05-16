#pragma once
#include <vector>
#include "Trainee.h"

class WorkingTrainee : public Trainee {
protected:
	std::vector<size_t> projectIndex;

public:
	WorkingTrainee(std::string name, int age, double salary, int weeksLeft, std::vector<size_t>projectIndex);

	virtual double getSalary() const override;

	std::vector<size_t> getProjectIndex() const;
};
