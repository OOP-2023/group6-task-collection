#include <iostream>
#include <fstream>
using namespace std;
#ifndef VECTOR_HEADER
#define VECTOR_HEADER

/// @brief Клас, който представлява
/// динамичен масив
class vector {
public:
    /// @brief Създава празен контейнер с capacity 8.
    vector()
    {
        size = 0;
        capacity = 8;
        data = new int[capacity] {0};
    }

    vector(const vector& source)
    {
        copy(source);
    }

    vector(vector&& source)
    {
        size = source.size;
        capacity = source.capacity;
        data = source.data;
        source.data = nullptr;
        source.size = 0, source.capacity = 0;
    }

    vector& operator=(const vector& source)
    {
        if (this != &source)
        {
            free();
            copy(source);
        }
        return *this;
    }

    /// @brief Създава контейнер.
    /// @param argCap големината на контейнера.
    vector(int argCap)
    {
        size = 0;
        capacity = argCap;
        data = new int [capacity] {0};
    }

    /// @brief Създава контейнер.
    /// @param argCap Големината на контейнера.
    /// @param argDef Началната стойност на всички елементи.
    vector(int argCap, int argDef) // Създава контейнер с argCap големина като всеки елемент е равен на argDef.
    {
        size = 0;
        capacity = argCap;
        data = new int[capacity] {argDef};
    }
    /// @brief Връща число на дадена позиция.
    /// @param  Позицията от която искаме да четем.
    int operator[](size_t index) const
    {
        return data[index];
    }

    /// @brief Връща число на подадена позиция и позволява промяната му.
    /// @param  Позицията от която да четем или в която да пишем
    int& operator[](size_t index)
    {
        return data[index];
    }

    /// @brief Добавя елемент в колекцията.
    /// @param  Елемента, който добавяме.
    void push_back(int element)
    {
        if (size > capacity)
            resize();

        data[size++] = element;
    }

    /// @brief Премахва последния елемент от колекцията
    /// @return Последния елемент от колекцията
    int pop_back()
    {
        int last = data[size--];
        return last;
    }

    ~vector()
    {
        cout << "Destruction" << endl;
        delete[capacity] data;
    }

private:
    int* data;       // < Паметта, в която държим информацията
    size_t size;     // < Броя елементи в колекцията
    size_t capacity; // < Максималния брой елементи, които колекцията поддържа

    /// @brief Изтрива паметта
    void free()
    {
        delete[capacity] data;
    }

    /// @brief Копира обект
    void copy(const vector& source)
    {
        size = source.size;
        capacity = source.capacity;
        data = source.data;
    }

    /// @brief Удвоява размера на обекта. 
    void resize()
    {
        int* newData = new int[capacity * 2];

        for (size_t i = 0; i < size; i++)
        {
            newData[i] = data[i];
        }

        free(); // delete[capacity] data;

        data = newData, capacity *=2;
    }
};

#endif


int main()
{
    vector v;
    v.push_back(11);
    v.push_back(7);
    v.push_back(10);

    for (size_t i = 0; i < 3; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    v.pop_back();
    v.push_back(100);

    for (size_t i = 0; i < 3; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    
	return 0;
}