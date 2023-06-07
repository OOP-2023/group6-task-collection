#include <string>
#include <vector>


class Employee {
private:
    std::string name;
    int age;
    int salary;
public:
    Employee(std::string name, int age, int salary) {
        this->name = name;
        this->age = age;
        this->salary = salary;
    }
    std::string getName() {
        return name;
    }
    int getAge() {
        return age;
    }
    int getSalary() {
        return salary;
    }
    Employee(const Employee& obj) {
        name = obj.name;
        age = obj.age;
        salary = obj.salary;
    }
    virtual Employee* clone() const = 0;
    virtual ~Employee() {}
};

class Worker :virtual protected Employee {
private:
    int months;
    std::vector<unsigned> projects;
public:
    Worker(std::string name, int age, int salary, int months, std::vector<unsigned> projects) : Employee(name, age, salary) {
        this->months = months;
        this->projects = projects;
    }
    virtual Employee* clone() const override {
        return new Worker(*this);
    }
    ~Worker() {};
};

class Trainee : virtual protected Employee {
private:
    int weeksLeft;
public:
    Trainee(std::string name, int age, int salary, int weeksLeft) : Employee(name, age, salary) {
        this->weeksLeft = weeksLeft;
    }
    virtual Employee* clone() const override {
        return new Trainee(*this);
    }
    ~Trainee() {};
};

class WorkingTrainee : private Trainee, private Worker {
public:
    WorkingTrainee(std::string name, int age, int salary, int months, int weeksLeft, std::vector<unsigned> projects) : Employee(name, age, salary), Trainee(name, age, salary, weeksLeft), Worker(name, age, salary, months, projects) {
    }
    Employee* clone() const override {
        return new WorkingTrainee(*this);
    }
    ~WorkingTrainee() {};
};

class Firm {
private:
    std::vector<Employee*> employees;
    void sort() {
        int size = employees.size();
        for (int i = 0;i < size - 1;i++) {
            for (int j = i + 1;j < size;j++) {
                if (employees[i]->getSalary() > employees[j]->getSalary()) {
                    std::swap(employees[i], employees[j]);
                }
            }
        }
    }
public:
    int getLowestPaidSalary() {
        return employees[0]->getSalary();
    }
    double average() {
        int size = employees.size();
        int sum = 0;
        for (int i = 0;i < size;i++) {
            sum += employees[i]->getSalary();
        }
        return (sum * 1.0) / size;
    }
    void addWorker(const Worker& obj) {
        employees.push_back(obj.clone());
        sort();
    }
    void addTrainee(const Trainee& obj) {
        employees.push_back(obj.clone());
        sort();
    }
    void addWorkingTrainee(const WorkingTrainee& obj) {
        employees.push_back(obj.clone());
        sort();
    }
    bool twoSum(double val) const {

    }
};