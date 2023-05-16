#ifndef _EMPLOYEE_COLLECTION
#define _EMPLOYEE_COLLECTION
#include <vector>
#include "Employee.h"
#include "Trainee.h"
#include "WorkingTrainee.h"
#include "Worker.h"
class EmployeeCollection
{
private:
	std::vector<Employee*> employees;

	void add_employee(Employee* emp)
	{
		size_t idx_to_be_inserted_in = 0;
		for (size_t i = 0; i < employees.size(); i++)
		{
			if (employees[i]->get_salary() < emp->get_salary())
			{
				idx_to_be_inserted_in = i;
				break;
			}
		}

		employees.push_back(emp);

		for (int i = employees.size() - 1; i > idx_to_be_inserted_in; i--)
		{
			std::swap(employees[i], employees[i - 1]);
		}
	}

public:
	EmployeeCollection() = default;

	~EmployeeCollection()
	{
		for (size_t i = 0; i < employees.size(); i++)
		{
			delete employees[i];
		}
	}

	EmployeeCollection(const EmployeeCollection& other)
	{
		for (size_t i = 0; i < other.employees.size(); i++)
		{
			employees.push_back(other.employees[i]->clone());
		}
	}

	void add_trainee(size_t months_left, const std::string& name, size_t age, size_t salary)
	{
		employees.push_back(new Trainee(months_left, name, age, salary));
	}

	void add_worker(size_t months_worked, const std::string& name, size_t age, size_t salary)
	{
		employees.push_back(new Worker(months_worked, name, age, salary));
	}

	void add_working_trainee(size_t months_worked, size_t months_left, const std::string& name, size_t age, size_t salary)
	{
		employees.push_back(new WorkingTrainee(months_worked, months_left, name, age, salary));
	}

	double get_average_salary()
	{
		double average = 0;
		for (size_t i = 0; i < employees.size(); i++)
		{
			average += employees[i]->get_salary();
		}

		return average / employees.size();
	}

	void print_collection()
	{
		std::cout << "------------------------------------------" << std::endl;
		for (size_t i = 0; i < employees.size(); i++)
		{
			employees[i]->print();
		}
		std::cout << "------------------------------------------" << std::endl;
	}

	bool two_sum(size_t val) const
	{
		int start = 0;
		int end = employees.size() - 1;

		while (start < end)
		{
			size_t current_sum = employees[start]->get_salary() + employees[end]->get_salary();
			if (current_sum == val)
			{
				return true;
			}
			else if (current_sum > val)
			{
				start++;
			}
			else
			{
				end--;
			}


		}
		return false;
	}
};

#endif // !_EMPLOYEE_COLLECTION