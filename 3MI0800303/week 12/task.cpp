#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Employee {
    private:
        string name;
        int age;
        int salary;
    public:
        Employee(string name, int age, int salary) {
            this->name = name;
            this->age = age;
            this->salary = salary;
        }

        virtual Employee* clone() const = 0;
        virtual ~Employee() = default;

        string getName() const {
            return this->name;
        }
        int getAge() const {
            return this->age;
        }
        int getSalary() const {
            return this->salary;
        }
        void setName(const string name) {
            this->name = name;
        }
        void setAge(int age) {
            this->age = age;
        }
        void setSalary(int salary) {
            this->salary = salary;
        }
};

class Worker : public virtual Employee {
    private:
        unsigned months;
        vector<size_t> projects;
    public:
        Worker(string name, int age, int salary, unsigned months, vector<size_t> projects) : Employee(name, age, salary) {
            this->months = months;
            this->projects = projects;
        }

        ~Worker() override {}

        virtual Worker* clone() const override{
            return new Worker{*this};
        }
};

class Trainee : public virtual Employee {
    private:
        unsigned monthsTillEnd;
    public:
        Trainee(string name, int age, int salary, unsigned monthsTillEnd) : Employee(name, age, salary) {
            this->monthsTillEnd = monthsTillEnd;
        }

        ~Trainee() override {}

        virtual Trainee* clone() const override{
            return new Trainee{*this};
        }
};

class SpecialTrainee : public Trainee, public Worker {
    public:
        SpecialTrainee(string name, int age, int salary, unsigned monthsTillEnd, unsigned months, vector<size_t> projects) : Employee(name, age, salary), Worker(name, age, salary, months, projects), Trainee(name, age, salary, monthsTillEnd) {}
        ~SpecialTrainee() override {}
        virtual SpecialTrainee* clone() const override{
            return new SpecialTrainee{*this};
        }

};

class EmployeeCollection{
    private:
        vector<Employee*> data;
    
        void sortLast(){
            int size = data.size();
            if(size == 1) return; 

            unsigned salaryLook = data[size - 1]->getSalary();
            for (size_t i = 0; i < size; i++)
            {
                if(data[i]->getSalary() > salaryLook) {
                    swap(data[i], data[size - 1]);
                    salaryLook = data[i]->getSalary();
                }
            }
            

        }
    public:
        EmployeeCollection(){}
        EmployeeCollection(const EmployeeCollection& other){
            int size = other.data.size();
            for (size_t i = 0; i < size; i++)
            {
                data[i] = other.data[i]->clone();
            }
        }

        ~EmployeeCollection() {}

        void addWorker(const Worker& worker){
            data.push_back(worker.clone());
            sortLast();
        }
        void addTrainee(const Trainee& trainee){
            data.push_back(trainee.clone());
            sortLast();
        }
        void addSpeciakTrainee(const SpecialTrainee& specialTrainee){
            data.push_back(specialTrainee.clone());
            sortLast();
        }


};

int main(){
    EmployeeCollection collection;

    collection.addWorker(Worker("Ivan", 20, 1000, 12, {1, 2, 3}));
    collection.addTrainee(Trainee("Pesho", 20, 1000, 12));
    collection.addSpeciakTrainee(SpecialTrainee("Gosho", 20, 1000, 12, 12, {1, 2, 3}));

    return 1;
}