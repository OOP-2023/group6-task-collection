#ifndef _WORKING_TRAINEE
#define _WORKING_TRAINEE
#include "Trainee.h"
#include "Worker.h"
class WorkingTrainee : public Worker, public Trainee
{
private:
public:
	WorkingTrainee(size_t months_worked, size_t months_left, const std::string& name, size_t age, size_t salary) :
		Employee(name, age, salary), Worker(months_worked, name, age, salary), Trainee(months_left, name, age, salary)
	{
		std::cout << "Here in working trainee: " << name << std::endl;
	}

	~WorkingTrainee() = default;

	Employee* clone()
	{
		return new WorkingTrainee(*this);
	}


};


#endif // !_WORKING_TRAINEE
