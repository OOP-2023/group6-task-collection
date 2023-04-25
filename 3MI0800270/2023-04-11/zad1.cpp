#include <iostream>
#include "vector.hpp"
#include "array.hpp"

template <typename T>
const T& max(const T* arr, size_t size) {
    const T* temp = arr;
    for (size_t i = 1;i < size;i++) {
        if (arr[i] > *temp) {
            temp = arr + i;
        }
    }
    return *temp;
}

int main() {
    Vector<char> vec;
    vec.push_back('l');
    std::cout << vec.pop_back() << std::endl;
    vec[0] = 'a';
    std::cout << vec[0];

}