#ifndef VECTOR_HEADER
#define VECTOR_HEADER

/// @brief Клас, който представлява
/// динамичен масив
class vector {
public:
    /// @brief Създава празен контейнер с capacity 8.
    vector()
    {
        data = new int[8];
        size = 0;
        capacity = 8;
    }

    vector(const vector & ref)
    {
        copy(ref);
    }
    vector(vector && ref)
    {
        capacity = ref.capacity;
        size = ref.size;
        this->data = ref.data;
        ref.data = nullptr;
        ref.capacity = 0;
        ref.size = 0;
    }

    vector &operator=(const vector & ref)
    {
        if (this != &ref)
        {
            copy(ref);
        }
        return *this;
    };

    /// @brief Създава контейнер.
    /// @param argCap големината на контейнера.
    vector(int argCap)
    {
        data[argCap];
    }

    /// @brief Създава контейнер.
    /// @param argCap Големината на контейнера.
    /// @param argDef Началната стойност на всички елементи.
    vector(int argCap, int argDef) // Създава контейнер с argCap големина като всеки елемент е равен на argDef.
    {
        data[argCap];
        for (int i = 0; i < argCap; i++)
        {
            data[i] = argDef;
        }
    }
    /// @brief Връща число на дадена позиция.
    /// @param  Позицията от която искаме да четем.
    int operator[](int position) const
    {
        return data[position];
    }


    /// @brief Връща число на подадена позиция и позволява промяната му.
    /// @param  Позицията от която да четем или в която да пишем
    int &operator[](int position)
    {
        int paramToEdit = 0;
        data[position] = paramToEdit;
        return data[position];
    }

    /// @brief Добавя елемент в колекцията.
    /// @param  Елемента, който добавяме.
    void push_back(int element)
    {
        if (capacity == size)
        {
            resize();
        }
        data[size + 1] = element;
        size++;

    }


    /// @brief Премахва последния елемент от колекцията
    /// @return Последния елемент от колекцията
    int pop_back()
    {

    }

    ~vector();
private:
    int *data;       // < Паметта, в която държим информацията
    size_t size;     // < Броя елементи в колекцията
    size_t capacity; // < Максималния брой елементи, които колекцията поддържа

    /// @brief Изтрива паметта
    void free()
    {
        delete[] data;
    }

    /// @brief Копира обект
    void copy(const vector & ref)
    {
        capacity = ref.capacity;
        size = ref.size;
        this->data = new int[capacity];
        for (int i = 0; i < capacity; i++)
        {
            data[i] = ref.data[i];
        }
    }

    /// @brief Удвоява размера на обекта.
    void resize()
    {
        int* newData = new int[capacity * 2];
        for (int i = 0; i < capacity; ++i)
        {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }
};

#endif