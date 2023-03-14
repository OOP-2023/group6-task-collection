#ifndef VECTOR_HEADER
#define VECTOR_HEADER

/// @brief Клас, който представлява
/// динамичен масив
class vector {
public:
    /// @brief Създава празен контейнер с capacity 8.
    vector() {
        data = new int[8];
        size = 0;
        capacity = 8;
    }

    vector(const vector& other) {
        copy(other);
    }

    vector(vector&& other) {
        data = other.data;
        size = other.size;
        capacity = other.capacity;
    }

    vector& operator=(const vector& other) {
        if (this != &other)
        {
            free();
            copy(other);
        }
        
        return *this;
    }

    /// @brief Създава контейнер.
    /// @param argCap големината на контейнера.
    vector(int argCap) {
        data = new int[argCap];
        size = 0;
        capacity = argCap;
    }

    /// @brief Създава контейнер.
    /// @param argCap Големината на контейнера.
    /// @param argDef Началната стойност на всички елементи.
    vector(int argCap, int argDef) { // Създава контейнер с argCap големина като всеки елемент е равен на argDef.
        data = new int[argCap];
        size = 0;
        capacity = argCap;

        for (size_t i = 0; i < capacity; i++)
        {
            data[i] = argDef;
        }
    }

    /// @brief Връща число на дадена позиция.
    /// @param  Позицията от която искаме да четем.
    int operator[](size_t index) const {
        return data[index];
    }

    /// @brief Връща число на подадена позиция и позволява промяната му.
    /// @param  Позицията от която да четем или в която да пишем
    int& operator[](size_t index) {
        return data[index];
    }


    /// @brief Добавя елемент в колекцията.
    /// @param  Елемента, който добавяме.
    void push_back(int n) {
        if (size == capacity)
            resize();

        data[size] = n;
        size++;
    }

    /// @brief Премахва последния елемент от колекцията
    /// @return Последния елемент от колекцията
    int pop_back() {
        if (size == 0)
            return INT_MIN;

        size--;
        return data[size + 1];
    }

    ~vector() {
        free();
    }

private:
    int* data;       // < Паметта, в която държим информацията
    size_t size;     // < Броя елементи в колекцията
    size_t capacity; // < Максималния брой елементи, които колекцията поддържа

    /// @brief Изтрива паметта
    void free() {
        delete[] data;
    }

    /// @brief Копира обект
    void copy(const vector& other) {
        data = new int[other.capacity];

        for (size_t i = 0; i < other.size; i++)
        {
            data[i] = other.data[i];
        }

        size = other.size;
        capacity = other.capacity;
    }

    /// @brief Удвоява размера на обекта. 
    void resize() {
        int* nData = new int[capacity * 2];
        for (size_t i = 0; i < size; i++)
        {
            nData[i] = data[i];
        }

        capacity *= 2;
        free();
        data = nData;
    }
};

#endif