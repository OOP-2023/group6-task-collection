#ifndef _WORKER
#define _WORKER
#include "Employee.h"
#include <vector>
class Worker : public virtual Employee
{
private:
	size_t months_worked;
	std::vector<size_t> project_ids;
public:

	Worker(size_t months_worked, const std::string& name, size_t age, size_t salary) : Employee(name, age, salary)
	{
		std::cout << "Here in worker: " << name << std::endl;
		this->months_worked = months_worked;
	}

	~Worker() = default;

	Employee* clone() override
	{
		return new Worker(*this);
	}

	void set_months_worked(size_t m)
	{
		months_worked = m;
	}

	void add_month()
	{
		months_worked++;
	}

	size_t get_months_worked()
	{
		return months_worked;
	}

	size_t get_project_id_at(size_t idx)
	{
		return project_ids[idx];
	}

	size_t count_of_projects()
	{
		return project_ids.size();
	}

	void add_project_id(size_t project_id)
	{
		project_ids.push_back(project_id);
	}

};

#endif // !_WORKER
