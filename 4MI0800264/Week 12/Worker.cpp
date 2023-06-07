#include "Worker.h"


Worker::Worker(const Employee& employee, int inputMonthsWorked, std::vector<size_t> inputProjectsIndexes) : 
	Employee(employee.getName(), employee.getAge(), employee.getSalary())
{
	monthsWorked = inputMonthsWorked;
	projectsIndexes = inputProjectsIndexes;
}

Worker::Worker(std::string inputName, int inputAge, int inputSalary,
	int inputMonthsWorked, std::vector<size_t> inputProjectsIndexes) : Employee(inputName, inputAge,  inputSalary)
{
	monthsWorked = inputMonthsWorked;
	projectsIndexes = inputProjectsIndexes;
}

Employee* Worker::clone()
{
	return this;
}