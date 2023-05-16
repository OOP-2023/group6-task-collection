// Zad1_Week12.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;


class Employee {
private:
    std::string name;
    unsigned age;
    unsigned salary;
public:
    virtual void func() = 0;
    virtual ~Employee();
};
Employee::~Employee() {   
}

class Worker:public Employee {
private:
    unsigned months;
    std::vector<size_t> size;
};

class Trainee :public Employee {
private:
    unsigned weeksLeft;
};

class WorkingTrainee :public Employee {
private:
    unsigned hoursOfDailyWork;
};

class Company :public Worker, public Trainee, public WorkingTrainee, public Employee {
private:
    Employee* workers;
};
int main()
{
    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
