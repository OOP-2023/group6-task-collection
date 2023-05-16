#ifndef _EMPLOYEE
#define _EMPLOYEE
#include <string>
#include <iostream>
class Employee
{
private:
	std::string name;
	unsigned age;
	size_t salary;
public:

	Employee(const std::string& n, unsigned a, size_t s)
	{
		std::cout << "Here in employee: " << n << std::endl;
		name = n;
		age = a;
		salary = s;
	}

	virtual Employee* clone() = 0;

	virtual ~Employee() = default;

	void print()
	{
		std::cout << name << " " << age << " " << salary << std::endl;
	}

	void set_name(const char* n)
	{
		name = n;
	}

	const char* get_name()
	{
		return name.c_str();
	}

	void set_age(unsigned a)
	{
		age = a;
	}

	unsigned get_age()
	{
		return age;
	}

	void set_salary(size_t s)
	{
		salary = s;
	}

	size_t get_salary()
	{
		return salary;
	}
};

#endif // !_EMPLOYEE
