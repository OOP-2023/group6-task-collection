#include <iostream>
template <typename T>

class vector
{
private:
    T* data;
    size_t size;
    size_t capacity;
    void resize()
    {
        T* newData = new T[capacity * 2];
        for (size_t i = 0; i < capacity; i++)
        {
            newData[i] = data[i];
        }
        capacity *= 2;
        delete[] data;
        data = newData;
    }
    void free()
    {
        delete[] data;
    }
    void copy(const vector& vectorCpy)
    {
        size = vectorCpy.size;
        capacity = vectorCpy.capacity;
        data = new T[capacity];

        for (size_t i = 0; i < size; i++)
        {
            data[i] = vectorCpy.data[i];
        }
    }
    void setCap(size_t cap)
    {
        if (cap < 8)
            capacity = 8;
        else capacity = cap;
    }
public:
    vector()
    {
        size = 0;
        capacity = 8;
        data = new T[capacity];
    }
    vector(int argCap)
    {
        size = 0;
        setCap(argCap);
        data = new T[capacity];
    }
    vector(int argCap, T argDef)
    {
        size = 0;
        setCap(argCap);
        data = new T[capacity];
        for (size_t i = 0; i < capacity; i++)
        {
            data[i] = argDef;
        }
    }
    ~vector()
    {
        free();
    }
    vector(const vector& vectorCpy)
    {
        copy(vectorCpy);
    }
    vector(vector&& vectorObj)
    {
        size = vectorObj.size;
        capacity = vectorObj.capacity;
        data = vectorObj.data;

        vectorObj.size = 0;
        vectorObj.capacity = 0;
        vectorObj.data = nullptr;
    }
    vector& operator=(const vector& vectorObj)
    {
        if (this != &vectorObj)
        {
            free();
            copy(vectorObj);
        }
        return *this;
    }
    const T operator[](size_t index) const
    {
        if (index >= capacity)
            throw std::exception("Invalid argument");

        return data[index];
    }
    T& operator[](size_t index)
    {
        if (index >= capacity)
            throw std::exception("Invalid argument");

        return data[index];
    }
    void push_back(T number)
    {
        if (size == capacity) resize();
        data[size] = number;
        size++;
    }
    T pop_back()
    {
        T removedNumber = data[size];
        size--;
        return removedNumber;
    }
    const size_t getSize() const
    {
        return size;
    }
};
int main()
{
    vector<int> v(5, 3);
    v.push_back(5);
    v.push_back(3);
    v.push_back(2);
    std::cout << "v[2]: " << v[10] << std::endl;
    std::cout << "Ouput v" << std::endl;
    for (int i = 0; i < v.getSize(); i++)
        std::cout << v[i] << " ";
    std::cout << std::endl;

    v.pop_back();
    v.push_back(7);
    std::cout << std::endl;
    std::cout << "Ouput new v" << std::endl;
    for (int i = 0; i < v.getSize(); i++)
        std::cout << v[i] << " ";
    std::cout << std::endl;


    vector<double> v1;
    v1.push_back(5.2);
    v1.push_back(30.12);
    v1.push_back(2.15);
    std::cout << std::endl;
    std::cout << "Ouput v1" << std::endl;
    for (int i = 0; i < v1.getSize(); i++)
        std::cout << v1[i] << " ";
    std::cout << std::endl;


    vector<char> v2(10, 'g');
    v2.push_back('a');
    v2.push_back('N');
    v2.push_back('?');
    v2.push_back('F');
    v2.push_back('2');
    std::cout << std::endl;
    std::cout << "Ouput v2" << std::endl;
    for (int i = 0; i < v2.getSize() + 3; i++)
        std::cout << v2[i] << " ";
    std::cout << std::endl;
}