#include <iostream>

template<typename T, size_t x>
struct myArray
{
    T data[x];
};

int main()
{
    size_t i = 112;
    myArray<int, 112> arr;
    return 0;
}