#ifndef VECTOR_HEADER
#define VECTOR_HEADER

/// @brief Клас, който представлява
/// динамичен масив
class vector {
public:
    /// @brief Създава празен контейнер с capacity 8.
    vector()
        :size(0), capacity(8), data(new int[capacity])
    {
    }

    vector(const vector& v)
        : size(v.size), capacity(v.capacity), data(new int[v.capacity])
    {
        for (size_t i = 0; i < size; i++)
        {
            data[i] = v.data[i];
        }
    }
    vector(vector&&);

    vector& operator=(const vector& v)
    {
        if (&v == this) return *this;

        int* newData = new int[v.capacity];
        for (size_t i = 0; i < size; i++)
        {
            newData[i] = v.data[i];
        }

        delete[] data;
        data = newData;
        size = v.size;
        capacity = v.capacity;
        return *this;
    }

    /// @brief Създава контейнер.
    /// @param argCap големината на контейнера.
    vector(int argCap);

    /// @brief Създава контейнер.
    /// @param argCap Големината на контейнера.
    /// @param argDef Началната стойност на всички елементи.
    vector(int argCap, int argDef); // Създава контейнер с argCap големина като всеки елемент е равен на argDef.

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
    void push_back(int x)
    {

        if (size == capacity)
        {
            capacity *= 2;
        }

        int* newData = new int[capacity];

        for (size_t i = 0; i < size; i++)
        {
            newData[i] = data[i];
        }

        newData[size] = x;
        size++;

        delete[] data;
        data = newData;
    }

    /// @brief Премахва последния елемент от колекцията
    /// @return Последния елемент от колекцията
    int pop_back();

    ~vector()
    {
        delete[] data;
    }
private:
    int* data;       // < Паметта, в която държим информацията
    size_t size;     // < Броя елементи в колекцията
    size_t capacity; // < Максималния брой елементи, които колекцията поддържа

    /// @brief Изтрива паметта
    void free();

    /// @brief Копира обект
    void copy(const vector&);

    /// @brief Удвоява размера на обекта. 
    void resize();
};

#endif