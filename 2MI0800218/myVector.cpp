#include <iostream>

template <typename T>
class myVector {
private:
    T* data;
    size_t size;
    size_t capacity;

    void free() {
        delete[] data;
    }
    void copy(const myVector<T>& other) {
        data = new T[other.capacity];

        for (size_t i = 0; i < other.size; i++)
        {
            data[i] = other.data[i];
        }

        size = other.size;
        capacity = other.capacity;
    }
    void resize() {
        T* nData = new T[capacity * 2];
        for (size_t i = 0; i < size; i++)
        {
            nData[i] = data[i];
        }

        capacity *= 2;
        free();
        data = nData;
    }

public:
    myVector() {
        data = new T[8];
        size = 0;
        capacity = 8;
    }
    myVector(const myVector<T>&& other) {
        data = other.data;
        size = other.size;
        capacity = other.capacity;
    }
    myVector(const myVector<T>& other) {
        copy(other);
    }
    myVector(const size_t argCap) {
        data = new T[argCap];
        size = 0;
        capacity = argCap;
    }
    myVector(const size_t argCap, const T& argDef) {
        data = new T[argCap];
        size = 0;
        capacity = argCap;

        for (size_t i = 0; i < capacity; i++)
        {
            data[i] = argDef;
        }
    }
    myVector<T>& operator=(const myVector<T>& other) {
        if (this != &other)
        {
            free();
            copy(other);
        }
        return *this;
    }
    const T& operator[](size_t index) const {
        return data[index];
    }
    T& operator[](size_t index) {
        return data[index];
    }
    void push_back(const T& argDef) {
        if (size == capacity)
            resize();
        data[size] = argDef;
        size++;
    }
    T pop_back() {
        if (size == 0)

            size--;
        return data[size + 1];
    }
    const size_t getSize() const {
        return size;
    }
    void clear() {
        T* nData = new T[8];
        size = 0;
        capacity = 8;
        free();
        data = nData;
    }
    void setDataArgs(const T& argDef) {
        for (size_t i = 0; i < size; i++)
        {
            data[i] = argDef;
        }
    }
    ~myVector() {
        free();
    }
};