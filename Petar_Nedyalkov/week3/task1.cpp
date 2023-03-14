#include <iostream>
class vector
{
private:
    int* data;
    size_t size;
    size_t capacity;
    void resize()
    {
        int* newData = new int[capacity*2];
        for (size_t i = 0; i < capacity; i++)
        {
            newData[i] = data[i];
        }
        capacity *= 2;
        delete[] data;
        data = newData;
    }
    void free() //Подобие на Деконструктор
    {
        delete[capacity] data;
    }
    void copy(const vector& vectorCpy) //Подобие на Копи констриктор
    {
        size = vectorCpy.size;
        capacity = vectorCpy.capacity;
        data = new int[capacity];

        for (size_t i = 0; i < size; i++)
        {
            data[i] = vectorCpy.data[i];
        }
    }

public:
    vector() //Конструктор
    {
        size = 0;
        capacity = 8;
        data = new int[capacity] {0};
    }
    vector(int argCap) //Конструктор
    {
        size = 0;
        capacity = argCap;
        data = new int[capacity] {0};
    }
    vector(int argCap, int argDef) //Конструктор
    {
        size = 0;
        capacity = argCap;
        data = new int[capacity];
        for (size_t i = 0; i < capacity; i++)
        {
            data[i] = argDef; //Присвояваме arfDef на всеки един елемент
        }
    }
    ~vector() //Деконструктор
    {
        delete[capacity] data;
        //Може и да използваме просто free()
        std::cout << "Deconstruct" << std::endl; // Просто да видя, кога бива извикан 
    }
    vector(const vector& vectorCpy) //Копи конструктор
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
    vector& operator=(const vector& vectorObj) //Оператор =
    {
        if (this != &vectorObj)
        {
            free();
            copy(vectorObj);
        }

        return *this;
    }

    int operator[](size_t index) const 
    {
        return data[index];
    }

    int& operator[](size_t index)
    {
        return data[index];
    }

    void push_back(int number)
    {
        if (size == capacity) resize();
        data[size] = number;
        size++;
    }

    int pop_back()
    {
        int removedNumber = data[size];
        size--;
        return removedNumber;
    }
};
int main()
{
    //Тестове :)
    vector v(5);
    v.push_back(5);
    v.push_back(3);
    v.push_back(2);
    
    std::cout << v.operator[](2)<<std::endl;

    std::cout << "Ouput v" << std::endl;
    for (int i = 0; i < 3; i++)
    {
        std::cout << v[i]<<" ";
    }
    std::cout << std::endl;

    v.pop_back();
    v.push_back(7);
    std::cout << "Ouput new v" << std::endl;
    for (int i = 0; i < 3; i++)
    {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;

    vector v1(v);
    std::cout << "Ouput v1" << std::endl;
    for (int i = 0; i < 3; i++)
    {
        std::cout << v1[i] << " ";
    }
    std::cout << std::endl;
}
