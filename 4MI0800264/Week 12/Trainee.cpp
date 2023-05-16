#include "Trainee.h"


Trainee::Trainee(const Employee& employee, int inputWeeksLeftOfInternship) :
	Employee(employee.getName(), employee.getAge(), employee.getSalary())
{
	weeksLeftOfInternship = inputWeeksLeftOfInternship;
}

Trainee::Trainee(std::string inputName, int inputAge, int inputSalary, int inputWeeksLeftOfInternship) :
	Employee(inputName, inputAge, inputSalary)
{
	weeksLeftOfInternship = inputWeeksLeftOfInternship;
}

Employee* Trainee::clone()
{
	return this;
}