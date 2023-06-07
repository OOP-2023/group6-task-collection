#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Employee {
private:
	string name;
	unsigned age;
	double salary;
public:
	virtual Employee* clone() const = 0;
	virtual ~Employee() = default;
	double getSalary() {
		return salary;
	}
};
class Worker :public virtual Employee {
private:
	unsigned months;
	vector<size_t> index;
public:
	Employee* clone() const override {
		return new Worker(*this);
	}
};
class Trainee :public virtual Employee {
private:
	unsigned weeksLeft;
public:
	Employee* clone() const override {
		return new Trainee(*this);
	}
};
class WorkingTrainee : public Worker, public Trainee {
public:
	Employee* clone() const override {
		return new WorkingTrainee(*this);
	}
};
class Company {
private:
	vector<Employee*> data;
	void addEmployee(Employee* other) {
		data.push_back(other);
		std::sort(data.begin(), data.end());
	}
public:
	Company(const Company& other) {
		for (int i = 0; i < data.size(); ++i) {
			data[i] = other.data[i]->clone();
		}
	}
	void addWorker();
	void addTrainee();
	void addWorkingTrainee();
	double averageSalary();
	bool TwoSum(double val) const;
};
void Company::addWorker() {
	addEmployee(new Worker());
}
void Company::addTrainee() {
	addEmployee(new Trainee());
}
void Company::addWorkingTrainee() {
	addEmployee(new WorkingTrainee());
}
double Company::averageSalary() {
	double salarySum = 0;
	for (int i = 0; i < data.size(); ++i) {
		salarySum += data[i]->getSalary();
	}
	return salarySum / data.size();
}
bool Company::TwoSum(double val) const {
	for (int i = 0; i < data.size(); ++i) {
		for (int j = 1; j < data.size(); ++j) {
			if ((data[i]->getSalary() + data[j]->getSalary()) != val)
				return false;
		}
		return true;
	}
}
