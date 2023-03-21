#include <iostream>

struct VectorPair
{
    int element;
    size_t rang;

    VectorPair()
    {
        element = 0;
        rang = 0;
    }

    VectorPair(int el, size_t newRang)
    {
        this->element = el;
        this->rang = newRang;
    }

};

class vector
{
    VectorPair* data;
    size_t size;
    size_t capacity;
public:
    void free() {
        delete[] data;
    }


    void copyFrom(const vector& other) {
        size = other.size;
        capacity = other.capacity;

        data = new VectorPair[capacity];

        for (int i = 0; i < size; i++)
            data[i] = other.data[i];
    }

    void resize() {
        capacity = 2 * capacity;

        VectorPair* newMemory = new VectorPair[capacity];

        for (int i = 0; i < size; i++)
            newMemory[i] = data[i];

        delete[] data;
        data = newMemory;
    }

    vector() {
        size = 0;
        capacity = 8;
        data = new VectorPair[capacity];
    }

    vector(const vector& other) {
        copyFrom(other);
    }

    size_t getSize() const {
        return size;
    }

    void push_back(const VectorPair &elem) {
        if (size == capacity)
            resize();

        data[size++] = elem;
    }


    ~vector() {
        free();
    }
};

class priorityVector {
    vector v;

public:
    // Добавя елемент с ранг в колекцията.
    void enqueue(int elem, size_t rank)
    {
        VectorPair vecPair(elem, rank);
        v.push_back(vecPair);
    }

    // Поглежда кой е най - тежкия елемент.
    int peak() const;

    // Връща най - тежкия елемент и го премахва от колекцията.
    int dequeue();

private:
    // Начин, по който пазим колекция от типа
    // <число, ранг>. Може да преизползвате стар код.
    // Може и да ползвате std::pair  

};

int main()
{

}