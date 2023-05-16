#pragma once
#include<cstring>
#include <string>


class Employee
{
private:
	std::string _name= nullptr;
	size_t _age=0;
	size_t _salary=0;
public:
	Employee(std::string name, size_t age, size_t salary)
	{
		_name = name;
		_age = age;
		_salary = salary;
	}

	virtual Employee* clone() const = 0;

	virtual ~Employee() = default;
};

