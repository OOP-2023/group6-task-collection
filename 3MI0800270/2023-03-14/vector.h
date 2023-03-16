#ifndef VECTOR_HEADER
#define VECTOR_HEADER

#include <iostream>
/// @brief Клас, който представлява
/// динамичен масив
class Vector {

public:
    /// @brief Създава празен контейнер с capacity 8.
    Vector(); // v

    Vector(const Vector&); //v
    Vector(Vector&&); //v

    Vector& operator=(const Vector&); //v

    /// @brief Създава контейнер.
    /// @param argCap големината на контейнера.
    Vector(int argCap); // v

    /// @brief Създава контейнер.
    /// @param argCap Големината на контейнера.
    /// @param argDef Началната стойност на всички елементи.
    Vector(int argCap, int argDef); // Създава контейнер с argCap големина като всеки елемент е равен на argDef. // v

    /// @brief Връща число на дадена позиция.
    /// @param  Позицията от която искаме да четем.
    int operator[](size_t) const; // v

    /// @brief Връща число на подадена позиция и позволява промяната му.
    /// @param  Позицията от която да четем или в която да пишем
    int& operator[](size_t); // v

    /// @brief Добавя елемент в колекцията.
    /// @param  Елемента, който добавяме.
    void push_back(int); //v

    /// @brief Премахва последния елемент от колекцията
    /// @return Последния елемент от колекцията
    int pop_back(); // v



    ~Vector(); //v
private:
    int* data;       // < Паметта, в която държим информацията
    size_t size;     // < Броя елементи в колекцията
    size_t capacity; // < Максималния брой елементи, които колекцията поддържа

    /// @brief Изтрива паметта
    void free(); // v

    /// @brief Копира обект
    void copy(const Vector&); // v

    /// @brief Удвоява размера на обекта. 
    void resize(); // v
};

Vector::Vector(int argCap) {
    data = new int(argCap);
    size = 0;
    capacity = argCap;
}

Vector::Vector():Vector(8) {};

Vector::Vector(const Vector& vec) {
    size = vec.size;
    capacity = vec.capacity;
    data = new int(capacity);
    for (int i = 0;i < size;i++) {
        data[i] = vec.data[i];
    }
}
Vector::Vector(int argCap, int argDef) {
    data = new int(argCap);
    size = argCap;
    capacity = argCap;
    for (int i = 0;i < size;i++) {
        data[i] = argDef;
    }
}

Vector::Vector(Vector&& vec) {
    size = vec.size;
    capacity = vec.capacity;
    data = vec.data;
}

Vector& Vector::operator=(const Vector& vec) {
    copy(vec);
    return *this;
}

int Vector::operator[](size_t pos) const {
    if (pos >= size || pos < 0) {
        throw std::invalid_argument("invalid position");
    }
    return data[pos];
}
int& Vector::operator[](size_t pos) {
    if (pos >= size || pos < 0) {
        throw std::invalid_argument("invalid position");
    }
    return data[pos];
}

void Vector::push_back(int x) {
    if (size >= capacity) {
        resize();
    }
    data[size] = x;
    size++;
}

int Vector::pop_back() {
    if (size == 0) {
        throw  std::invalid_argument("invalid position");
    }
    size--;
    return data[size];
}

Vector::~Vector() {
    free();
}

void Vector::free() {
    delete[] data;
}

void Vector::copy(const Vector& vec) {
    free();
    *this = Vector(vec);
}

void Vector::resize() {
    int* ptr = new int(capacity * 2);
    for (int i = 0;i < size;i++) {
        ptr[i] = data[i];
        std::cout << "//" << ptr[i] << std::endl;
    }
    free();
    capacity *= 2;
    data = ptr;
}

#endif