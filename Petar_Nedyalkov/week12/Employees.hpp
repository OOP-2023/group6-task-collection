#ifndef _EMPLOYEES_HPP_
#define  _EMPLOYEES_HPP_

#include <vector>

class Employee {
	std::string name;
	size_t age;
	size_t salary;
public:
	Employee();
	~Employee() = default;
	Employee(const std::string& , size_t, size_t);
	virtual Employee* clone() const = 0;
	std::string getName() const;
	size_t getAge() const;
	size_t getSalary() const;
};

class Worker : public virtual  Employee {
protected:
	size_t countOfMonths;
	std::vector<size_t> projects;
public:
	Worker(const std::string&, size_t, size_t,size_t);
	Employee* clone() const override;
	size_t getWorkingMonths() const;
	size_t addNewProject(size_t);

};

class Trainee : public virtual Employee {
protected:
	size_t weeksLeft;
public:
	Trainee() = default;
	Employee* clone() const override;
};

class WorkingTrainee : public Worker, public Trainee {
public:
	Employee* clone() const override;
};

class Company {
	std::vector<Employee*> data;
	void copy(const Company&);
	void free();
public:
	Company() = default;
	~Company();
	Company(const Company&);
	Company& operator=(const Company&);
	void addWorker(const Worker& current);
	void addTrainee(const Trainee& current);
	void addWorkingTrainee(const WorkingTrainee& current);

};

#endif 