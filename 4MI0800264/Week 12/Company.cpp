#include "Company.h"

void Company::sort()
{
	Employee* tempPointer = data[0];
	bool wasSwapped = false;

	for (size_t i = 0; i < data.size() - 1; i++)
	{
		for (size_t j = i; j < data.size() - 1; j++)
		{
			if (data[j]->getSalary() > data[j + 1]->getSalary())
			{
				tempPointer = data[j];
				data[j] = data[j + 1];
				data[j + 1] = tempPointer;

				wasSwapped = true;
			}
		}

		if (!wasSwapped)
			break;
	}
}

Company::Company()
{
	
}

Company::Company(const Company& other)
{
	for (size_t i = 0; i < data.size(); i++)
	{
		data[i] = other.data[i]->clone();
	}
}

void Company::addWorker(Worker* const worker)
{
	data.push_back(worker);
	sort();
}

void Company::addTrainee(Worker* const trainee)
{
	data.push_back(trainee);
	sort();
}

void Company::addWorkingTrainee(Worker* const workingTrainee)
{
	data.push_back(workingTrainee);
	sort();
}

double Company::getAverageSalary()
{
	double avg = 0;

	for (size_t i = 0; i < data.size(); i++)
	{
		avg += data[i]->getSalary();
	}

	return avg / data.size();
}