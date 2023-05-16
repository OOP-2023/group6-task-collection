#ifndef WEEK11_EMPLOYEE_H
#define WEEK11_EMPLOYEE_H
#include <iostream>
#include <vector>

class Employee
{
protected:
    std::string name;
    int age;
    int salary;
public:
    virtual Employee* clone() = 0;
};
class Worker : virtual public  Employee
{
protected:
    int monthsWorked;
    std::vector<size_t> projectIndices;
public:
    Employee* clone() override;
};
class Trainee : virtual public Employee
{
protected:
    int weeksTillEnd;
public:
    Employee* clone() override;
};
class WorkingTrainee: public Worker, public Trainee
{
public:
    Employee* clone() override;
};
class EmployeeCollection
{
private:
    std::vector<Employee*> collection;
public:
    EmployeeCollection(const EmployeeCollection& other);
    void addWorker();
    void addTrainee();
    void addWorkingTrainee();
};



#endif //WEEK11_EMPLOYEE_H
