#include "Employee.hpp"
#include <iostream> 
int main() {
    std::vector<unsigned> vec;
    vec.push_back(123123);
    WorkingTrainee gec("mr bubbles", 37, 3, 3, 7, vec);
    Worker gec2("bratleto", 20, 2, 2, vec);
    Firm firm;
    firm.addWorkingTrainee(gec);
    firm.addWorker(gec2);
    std::cout << firm.average() << std::endl;
}