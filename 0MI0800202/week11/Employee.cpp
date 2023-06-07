#include "Employee.h"


EmployeeCollection::EmployeeCollection(const EmployeeCollection &other)
{
    int size = collection.size();
    for (int i = 0; i < size; ++i)
    {
        collection[i] = other.collection[i]->clone();
    }
}

Employee *Worker::clone()
{
    return new Worker(*this);
}

Employee *Trainee::clone()
{
    return new Trainee(*this);
}

Employee *WorkingTrainee::clone()
{
    return new WorkingTrainee(*this);
}
