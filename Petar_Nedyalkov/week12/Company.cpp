#include <iostream>
#include "Employees.hpp"

void Company::free()
{
	for (size_t i = 0; i < data.size(); i++)
		delete data[i];
}

void Company::copy(const Company& other) {
	for (size_t i = 0; i < data.size(); i++)
		data[i] = other.data[i]->clone();
}

Company::~Company() {
	free();
}

Company::Company(const Company& other) {
	copy(other);
}

Company& Company::operator=(const Company& other) {
	if (this != &other)
	{
		free();
		copy(other);
	}
	return *this;
}

void Company::addWorker(const Worker& current)
{
	data.push_back(new Worker(current));
}

void Company::addTrainee(const Trainee& current)
{
	data.push_back(new Trainee(current));
}

void Company::addWorkingTrainee(const WorkingTrainee& current)
{
	data.push_back(new WorkingTrainee(current));
}