#include <iostream>
#include "Employees.hpp"
#pragma warning (disable : 4996)

Worker::Worker(const std::string& arg , size_t _age, size_t _salary, size_t months) : Employee(arg,_age,_salary) {
	countOfMonths = months;
}

size_t Worker::getWorkingMonths() const {
	return countOfMonths;
}

Employee* Worker::clone() const {
	return new Worker(*this);
}

size_t Worker::addNewProject(size_t indexOfProject)
{
	projects.push_back(indexOfProject);
	return indexOfProject;
}

Employee* WorkingTrainee::clone() const {
	return new WorkingTrainee(*this);
}

Employee* Trainee::clone() const {
	return new Trainee(*this);
}


