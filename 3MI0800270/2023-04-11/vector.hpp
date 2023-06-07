#ifndef VECTOR_HEADER
#define VECTOR_HEADER

#include <iostream>
/// @brief Клас, който представлява
/// динамичен масив
template <typename T>
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
    Vector(int argCap, T argDef); // Създава контейнер с argCap големина като всеки елемент е равен на argDef. // v

    /// @brief Връща число на дадена позиция.
    /// @param  Позицията от която искаме да четем.
    T operator[](size_t) const; // v

    /// @brief Връща число на подадена позиция и позволява промяната му.
    /// @param  Позицията от която да четем или в която да пишем
    T& operator[](size_t); // v

    /// @brief Добавя елемент в колекцията.
    /// @param  Елемента, който добавяме.
    void push_back(T); //v

    /// @brief Премахва последния елемент от колекцията
    /// @return Последния елемент от колекцията
    T pop_back(); // v



    ~Vector(); //v
private:
    T* data;       // < Паметта, в която държим информацията
    size_t size;     // < Броя елементи в колекцията
    size_t capacity; // < Максималния брой елементи, които колекцията поддържа

    /// @brief Изтрива паметта
    void free(); // v

    /// @brief Копира обект
    void copy(const Vector&); // v

    /// @brief Удвоява размера на обекта. 
    void resize(); // v
};

template<typename T>
Vector<T>::Vector(int argCap) {
    data = new T(argCap);
    size = 0;
    capacity = argCap;
}
template<typename T>
Vector<T>::Vector():Vector<T>(8) {};

template<typename T>
Vector<T>::Vector(const Vector<T>& vec) {
    size = vec.size;
    capacity = vec.capacity;
    data = new T(capacity);
    for (int i = 0;i < size;i++) {
        data[i] = vec.data[i];
    }
}

template<typename T>
Vector<T>::Vector(int argCap, T argDef) {
    data = new T(argCap);
    size = argCap;
    capacity = argCap;
    for (int i = 0;i < size;i++) {
        data[i] = argDef;
    }
}

template<typename T>
Vector<T>::Vector(Vector&& vec) {
    size = vec.size;
    capacity = vec.capacity;
    data = vec.data;
}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& vec) {
    copy(vec);
    return *this;
}
template<typename T>
T Vector<T>::operator[](size_t pos) const {
    if (pos >= size || pos < 0) {
        throw std::out_of_range("invalid position");
    }
    return data[pos];
}
template<typename T>
T& Vector<T>::operator[](size_t pos) {
    if (pos >= size || pos < 0) {
        throw std::out_of_range("invalid position");
    }
    return data[pos];
}

template<typename T>
void Vector<T>::push_back(T x) {
    if (size >= capacity) {
        resize();
    }
    data[size] = x;
    size++;
}

template<typename T>
T Vector<T>::pop_back() {
    if (size == 0) {
        throw  std::invalid_argument("invalid position");
    }
    size--;
    return data[size];
}

template<typename T>
Vector<T>::~Vector() {
    free();
}

template<typename T>
void Vector<T>::free() {
    delete[] data;
}

template<typename T>
void Vector<T>::copy(const Vector& vec) {
    free();
    *this = Vector(vec);
}

template<typename T>
void Vector<T>::resize() {
    T* ptr = new T[capacity * 2];
    for (int i = 0;i < size;i++) {
        ptr[i] = data[i];
        std::cout << "//" << ptr[i] << std::endl;
    }
    free();
    capacity *= 2;
    data = ptr;
}

#endif