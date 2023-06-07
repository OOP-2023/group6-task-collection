#include <iostream>
#include <vector>
class Employee{
protected:
    std::string name;
    unsigned age;
    double salary;
public:
    //clone function - it must be virtual
    virtual Employee* clone() =0;
    //constructor
    Employee(std::string _name, unsigned _age, double _salary){
        name=_name;
        age = _age;
        salary = _salary;
    }
};

class Worker: public  virtual Employee{
protected:
    unsigned months;
    std::vector<size_t> projects;
public:
    Employee* clone() override{
        return new Worker(*this);
    }
    //constructor
    Worker(std::string _name, unsigned _age, double _salary, unsigned _months, std::vector<size_t> project): Employee(name=_name, age=_age, salary=_salary){
        months=_months;
        projects=project;
    }
};

class Trainee: public virtual Employee{
protected:
    unsigned rest_weeks;
public:
    Employee* clone() override{
        return new Trainee(*this);
    }
    //constructor
    Trainee(std::string _name, unsigned _age, double _salary, unsigned rest):Employee(name=_name, age=_age, salary=_salary){
        rest_weeks=rest;
    }
};

class WorkingTrainee: public Worker, public Trainee{
public:
    //constructor
    WorkingTrainee(std::string _name, unsigned _age, double _salary, unsigned _months, std::vector<size_t> project, unsigned rest):
        Employee(name=_name, age=_age, salary=_salary),
        Worker(name=_name, age=_age, salary=_salary, months=_months, projects=project),
        Trainee(name=_name, age=_age, salary=_salary, rest_weeks=rest){}

    Employee* clone() override{
        return new WorkingTrainee(*this);
    }

};

class Company{
};

int main(){
}
