#include <iostream>
#include <vector>

class Employee {
protected:
    std::string name;
    unsigned age;
    int salary;
public:
    Employee(const std::string& _name,unsigned _age,int _salary)
    {
        name = _name;
        age = _age;
        salary = _salary;
    }
    
    virtual Employee* clone() const = 0;

    virtual ~Employee() = default;
};

class Worker : public virtual Employee {
protected:
    int count;
    std::vector<size_t> projects;
public:
    Worker(const std::string& name, unsigned age, int salary, int _count, std::vector<size_t> _projects) : Employee(name, age, salary)
    {
        count = _count;
        projects = _projects;
    }
    Employee* clone() const override {
        return new Worker(*this);
    }

    ~Worker() = default;
};

class Trainee: public virtual Employee{
protected:
    int weeks;
public:
    Trainee(const std::string& name, unsigned age, int salary, int _weeks) : Employee(name, age, salary)
    {
        weeks = _weeks;
    }
    Employee* clone() const override {
        return new Trainee(*this);
    }

    ~Trainee() = default;
};

class TraineeWorker : public Worker, public Trainee {
    int height;
public:
    TraineeWorker(const Employee& current, int _weeks, int _count, std::vector<size_t> _projects,int _height) :
        Worker(name, age, salary, _count, _projects),
        Trainee(name, age, salary, _weeks),
        Employee(name, age, salary) 
    {
        height = _height;
    }

    Employee* clone() const override {
        return new TraineeWorker(*this);
    }

    ~TraineeWorker() = default;
};

class Company {
    std::vector<Employee*> data;
public:
    Company(const Company& other)
    {
        for (size_t i = 0; i < data.size(); i++)
        {
            data[i] = other.data[i]->clone();
        }

    }

    void addWorker(Worker* worker) {
        data.push_back(worker);
    }

    void addTrainee(Trainee* trainee) {
        data.push_back(trainee);
    }

    void addWorkingTrainee(TraineeWorker* traineeWorker) {
        data.push_back(traineeWorker);
    }
};

int main()
{
    
}
