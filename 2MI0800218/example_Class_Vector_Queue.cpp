#include <iostream>
#include <fstream>
#include <string>

class Example {
private:
    int data;
    std::string buff;

    void copy(const Example& other) {
        data = other.data;
        buff = other.buff;
    }

public:
    Example() {
        data = 0;
        buff = "";
    }

    Example(const Example&& other) {
        data = other.data;
        buff = other.buff;
    }

    Example(const Example& other) {
        copy(other);
    }

    Example(const int dataArg, const std::string buffArg) {
        data = dataArg;
        buff = buffArg;
    }

    void setData(const int d) {
        data = d;
    }

    void setBuff(const std::string buffArg) {
        buff = buffArg;
    }

    std::string getBuff() const {
        return buff;
    }

    int getData() const {
        return data;
    }

    Example& operator=(const Example& other) {
        if (data != other.data && buff != other.buff)
        {
            data = other.data;
            buff = other.buff;
        }

        return *this;
    }
};

class vector {
public:
    vector() {
        data = new Example[8];
        size = 0;
        capacity = 8;
    }

    vector(const vector& other) {
        copy(other);
    }

    vector(const vector&& other) {
        data = other.data;
        size = other.size;
        capacity = other.capacity;
    }

    vector(const size_t argCap) {
        data = new Example[argCap];
        size = 0;
        capacity = argCap;
    }

    vector(const size_t argCap, const Example& argDef) {
        data = new Example[argCap];
        size = 0;
        capacity = argCap;

        for (size_t i = 0; i < capacity; i++)
        {
            data[i] = argDef;
        }
    }

    vector& operator=(const vector& other) {
        if (this != &other)
        {
            free();
            copy(other);
        }

        return *this;
    }

    Example operator[](size_t index) const {
        return data[index];
    }

    Example& operator[](size_t index) {
        return data[index];
    }

    void push_back(Example exArg) {
        if (size == capacity)
            resize();

        data[size] = exArg;
        size++;
    }

    Example pop_back() {
        if (size == 0)
            return { 0, "" };

        size--;
        //ako stane prekaleno maluk shrink funkciq?
        return data[size + 1];
    }

    size_t getSize() const {
        return size;
    }

    void clear() {
        Example* nData = new Example[8];
        size = 0;
        capacity = 8;
        free();
        data = nData;
    }

    ~vector() {
        free();
    }

private:
    Example* data;
    size_t size;
    size_t capacity;

    void free() {
        delete[] data;
    }

    void copy(const vector& other) {
        data = new Example[other.capacity];

        for (size_t i = 0; i < other.size; i++)
        {
            data[i] = other.data[i];
        }

        size = other.size;
        capacity = other.capacity;
    }

    void resize() {
        Example* nData = new Example[capacity * 2];
        for (size_t i = 0; i < size; i++)
        {
            nData[i] = data[i];
        }

        capacity *= 2;
        free();
        data = nData;
    }
};

class ExampleQueue {
private:
    vector exData;
    size_t tail;
    size_t head;
    bool isEmpty;

public:
    ExampleQueue() {
        exData = vector();
        tail = exData.getSize();
        head = 0;
        isEmpty = true;
    }

    ExampleQueue(const ExampleQueue&& other) {
        exData = other.exData;
        tail = other.tail;
        head = other.head;
        isEmpty = other.isEmpty;
    }

    ExampleQueue(const ExampleQueue& other) {
        exData = vector(other.exData);
        tail = other.tail;
        head = other.head;
        isEmpty = other.isEmpty;
    }

    void enqueue(const Example& exArg) {
        exData.push_back(exArg);
        tail = exData.getSize();
        isEmpty = false;
    }

    bool queueIsEmpty() {
        isEmpty = exData.getSize();
        return isEmpty;
    }

    Example dequeue() {
        if (isEmpty)
        {
            return { 0, "" };
        }
        Example headEx = exData[head];
        if (head == tail)
        {
            exData.clear();
            head = 0;
            tail = 0;
            isEmpty = true;
        }
        else
            head++;
        return headEx;
    }

    vector getExData() const {
        return exData;
    }

    size_t getTail() const {
        return tail;
    }

    size_t getHead() const {
        return head;
    }
};