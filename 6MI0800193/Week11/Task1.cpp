#include <iostream>
#include "Trainee.h"
#include "Worker.h"
#include "WorkingTrainee.h"
#include "EmployeeCollection.h"

int main()
{
    EmployeeCollection ec;

    ec.add_worker(16, "Ivan", 22, 2600);
    ec.add_working_trainee(1, 6, "Peter", 20, 2000);
    ec.add_worker(16, "Ivan", 22, 1900);
    ec.add_trainee(3, "George", 19, 1500);
    ec.add_worker(17, "Ivan", 23, 100);

    std::cout << ec.get_average_salary() << std::endl;

    ec.print_collection();

    std::cout << "Two sum - 2000 - " << ec.two_sum(2000) << std::endl;
    std::cout << "Two sum - 1600 - " << ec.two_sum(1600) << std::endl;
    std::cout << "Two sum - 9000 - " << ec.two_sum(9000) << std::endl;
}
