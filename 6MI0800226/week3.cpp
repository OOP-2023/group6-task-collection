#include "vector.h"
#include <stdexcept>

const int DEFAULT_CAPACITY = 8;

vector::vector() {
    data = new int[DEFAULT_CAPACITY] {0};
    size = 0;
    capacity = DEFAULT_CAPACITY;
}
vector::vector(const vector& vec) {
    data = new int[vec.capacity] {0};
    for (size_t i = 0; i < vec.size; i++)
    {
        data[i] = vec.data[i];
    }

    size = vec.size;
    capacity = vec.capacity;
}
vector::vector(vector&& vec) {
    data = vec.data;
    size = vec.size;
    capacity = vec.capacity;

    vec.~vector();
}

vector::vector(int argCap) {
    data = new int[argCap] {0};
    size = 0;
    capacity = argCap;
}

vector::vector(int argCap, int argDef) {
    data = new int[argCap] {argDef};
    size = 0;
    capacity = DEFAULT_CAPACITY;
}
void vector::free() {
    delete[] data;
    data = nullptr;
}

vector::~vector() {
    if (data != nullptr) this->free();
}

void vector::resize() {
    int* newData = new int[capacity * 2];
    for (size_t i = 0; i < size; i++)
        newData[i] = data[i];

    this->free();
    data = newData;
    capacity *= 2;
}

void vector::push_back(int a) {
    if (size == capacity)
        resize();

    data[size++] = a;
}

int vector::pop_back() {
    int temp = data[size];
    size--;
    return temp;
}

int vector::operator[](size_t i) const {
    if (i > capacity) throw std::out_of_range("Out of range");
    return data[i];
}

int& vector::operator[](size_t i) {
    if (i > capacity) throw std::out_of_range("Out of range");
    return data[i];
}

void vector::copy(const vector& other) {
    if (other.size > capacity) throw std::out_of_range("Out of range");
    for (size_t i = 0; i < other.size; i++)
    {
        data[i] = other.data[i];
    }
    capacity = other.capacity;
    size = other.size;
}

// vector& vector::operator=(const vector & vec){
//     if(this != *vec){
//         free();
//         copy(vec);
//     }
// }