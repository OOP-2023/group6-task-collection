#ifndef _TRAINEE
#define _TRAINEE
#include "Employee.h"
class Trainee : public virtual Employee
{
private:
	size_t months_left;
public:

	Trainee(size_t months_left, const std::string& name, size_t age, size_t salary) : Employee(name, age, salary)
	{
		std::cout << "Here in trainee: " << name << std::endl;
		this->months_left = months_left;
	}

	~Trainee() = default;

	Employee* clone() override
	{
		return new Trainee(*this);
	}

	void set_months_left(size_t m)
	{
		months_left = m;
	}

	size_t get_months_left()
	{
		return months_left;
	}
};

#endif // !
