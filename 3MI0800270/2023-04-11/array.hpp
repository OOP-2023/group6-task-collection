#include <stdexcept>

template<typename T, unsigned size>
class array
{
private:
    T data[size];
public:
    array();
    array& operator=(const T* arr);
    const T& operator[](unsigned pos) const;
    T& operator[](unsigned pos);
};

template<typename T, unsigned size>
array<T, size>::array() {}

template<typename T, unsigned size>
const T& array<T, size>::operator[](unsigned pos) const {
    if (pos<0 || pos>size) {
        throw std::invalid_argument("pos out out range")
    }
    return data[pos];
}

template<typename T, unsigned size>
array<T, size>& array<T, size>::operator=(const T* arr) {
    for (int i = 0; i < size; i++) {
        data[i] = arr[i];
    }
    return *this;
}

template<typename T, unsigned size>
T& array<T, size>::operator[](unsigned pos) {
    if (pos<0 || pos>size) {
        throw std::invalid_argument("pos out out range")
    }
    return data[pos];
}

