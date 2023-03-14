#include <iostream>
#include "vector.h"

int main() {
    vector vec;
    for (size_t i = 0; i < 8; i++)
    {
        vec.push_back(i);
    }
    
    std::cout << vec[3];

    return 1;
}