#include <iostream>
template <typename T>
class MyVector {
private:
    T* data;
    std::size_t size;
    std::size_t capacity;

    T reset();
    T resize();
    void copy(std::size_t, std::size_t, const T*);

    T shift_left(std::size_t);
    T shift_right(std::size_t);

public:

    MyVector(std::size_t = 16);
    MyVector(const MyVector&);
    MyVector& operator=(const MyVector&);
    ~MyVector();

    std::size_t length() const;

    T insertAt(std::size_t, const T&);

    T remove(std::size_t);

    T pop_front();
    T push_front(const T&);

    T pop_back();
    T push_back(const T&);

    T& operator[](std::size_t);
    const T& operator[](std::size_t) const;
};
template <typename T>
MyVector<T>::MyVector(std::size_t capacity) {
    this->size = 0;
    this->capacity = capacity;
    this->data = new int[this->capacity];
}
template <typename T>
MyVector<T>::MyVector(const MyVector& other) {
    this->copy(other.size, other.capacity, other.data);
}
template <typename T>
 MyVector<T>& MyVector<T>::operator=(const MyVector<T>& other) {
    if (this != &other) {
        this->reset();
        this->copy(other.size, other.capacity, other.data);
    }

    return *this;
}
 template <typename T>
MyVector<T>::~MyVector() {
    this->reset();
}
template <typename T>
std::size_t MyVector<T>::length() const {
    return this->size;
}
template <typename T>
T MyVector<T>::insertAt(std::size_t position, const T& element) {
    if (position > this->size) {
        throw std::runtime_error("index out of bounds");
    }

    if (this->size == this->capacity) {
        this->resize();
    }

    this->shift_right(position);
    this->data[position] = element;
}
template <typename T>
T MyVector<T>::remove(std::size_t position) {
    if (position >= this->size) {
        throw std::runtime_error("index out of bounds");
    }

    T result = this->data[position];

    this->shift_left(position);

    return result;
}
template <typename T>
T MyVector<T>::pop_front() {
    if (this->size < 1) {
        throw std::runtime_error("index out of bounds");
    }

    return this->remove(0);
}
template <typename T>
T MyVector<T>::push_front(const T& element) {
    this->insertAt(0, element);
}
template <typename T>
T MyVector<T>::pop_back() {
    if (this->size < 1) {
        throw std::runtime_error("index out of bounds");
    }

    return this->remove(this->size - 1);
}
template <typename T>
T MyVector<T>::push_back(const T& element) {
    this->insertAt(this->size, element);
}
template <typename T>
T& MyVector<T>::operator[](std::size_t index) {
    if (index >= this->size) {
        throw std::runtime_error("index out of bounds");
    }

    return this->data[index];
}
template <typename T>
const T& MyVector<T>::operator[](std::size_t index) const {
    if (index >= this->size) {
        throw std::runtime_error("index out of bounds");
    }

    return this->data[index];
}
template <typename T>
T MyVector<T>::reset() {
    this->size = 0;
    this->capacity = 0;
    delete[] this->data;
}
template <typename T>
T MyVector<T>::resize() {
    T* old = this->data;

    copy(this->size, this->capacity * 2, old);

    delete[]old;
}
MyVector<T>::copy(std::size_t size, std::size_t capacity, const T* data) {
    this->size = size;
    this->capacity = capacity;
    this->data = new T[this->capacity];

    for (std::size_t index = 0; index < this->size; ++index) {
        this->data[index] = data[index];
    }
}
template <typename T>
T MyVector<T>::shift_left(std::size_t start) {
    this->size = this->size - 1;

    for (std::size_t index = start; index < this->size; index++) {
        this->data[index] = this->data[index + 1];
    }
}
template <typename T>
T MyVector<T>::shift_right(std::size_t start) {
    this->size = this->size + 1;

    for (std::size_t index = this->size - 1; index > start; index--) {
        this->data[index] = this->data[index - 1];
    }
}

int main()
{
    MyVector<int> v = MyVector<int>(3);

    for (std::size_t index = 0; index < 100; ++index) {
        v.push_back(index);
    }

    // for(std::size_t index = 0; index < v.length(); ++index) {
    //     std::cout << "v[" << index << "]: " << v[index] << std::endl;
    // }


    while (v.length() > 0) {
        std::cout << "v[" << 100 - v.length() << "]: " << v.pop_front() << std::endl;
    }


    return 0;
}