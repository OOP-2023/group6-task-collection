#ifndef VECTOR_HEADER
#define VECTOR_HEADER
/// @brief Клас, който представлява
/// динамичен масив

class Pair {
public:
    int value;
    size_t rank;

    Pair& operator=(const Pair);

    Pair(const int v, const int r);
    Pair();
};

Pair& Pair::operator=(const Pair pair) {
    this->value = pair.value;
    this->rank = pair.rank;
    return *this;
}

Pair::Pair(const int v, const int r) {
    value = v;
    rank = r;
}
Pair::Pair() {
    value = 0;
    rank = 0;
}

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
    Vector(int argCap, int argDefValue, int argDefRank); // Създава контейнер с argCap големина като всеки елемент е равен на argDef. // v

    /// @brief Връща число на дадена позиция.
    /// @param  Позицията от която искаме да четем.
    Pair operator[](size_t) const; // v

    /// @brief Връща число на подадена позиция и позволява промяната му.
    /// @param  Позицията от която да четем или в която да пишем
    Pair& operator[](size_t); // v

    /// @brief Добавя елемент в колекцията.
    /// @param  Елемента, който добавяме.
    void push_back(int elem, size_t rank); //v

    /// @brief Премахва последния елемент от колекцията
    /// @return Последния елемент от колекцията
    Pair pop_back(); // v

    int getElementWithBiggestRank();
    int peak() const;

    int newpos(int x);

    int getSize() const;

    ~Vector(); //v
private:
    Pair* data;       // < Паметта, в която държим информацията
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
    data = new Pair[argCap];
    size = 0;
    capacity = argCap;
}

Vector::Vector():Vector(8) {};

Vector::Vector(const Vector& vec) {
    size = vec.size;
    capacity = vec.capacity;
    data = new Pair[capacity];
    for (int i = 0;i < size;i++) {
        data[i] = vec.data[i];
    }
}
Vector::Vector(int argCap, int argDefValue, int argDefRank) {
    data = new Pair[argCap];
    size = argCap;
    capacity = argCap;
    for (int i = 0;i < size;i++) {
        data[i] = Pair(argDefValue, argDefRank);
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

Pair Vector::operator[](size_t pos) const {
    if (pos >= size || pos < 0) {
        throw std::out_of_range("invalid position");
    }
    return data[pos];
}
Pair& Vector::operator[](size_t pos) {
    if (pos >= size || pos < 0) {
        throw std::out_of_range("invalid position");
    }
    return data[pos];
}

int Vector::getSize() const {
    return size;
}

int Vector::newpos(int x) {
    int res = 0;
    for (int i = 0;i < size;i++) {
        if (data[i].rank <= x) {
            res++;
        }
        else {
            return res;
        }
    }
    return res;
}

void Vector::push_back(int elem, size_t rank) {
    if (size >= capacity) {
        resize();
    }
    int pos = newpos(rank);
    for (int i = size - 1;i >= pos;i--) {
        data[i + 1] = data[i];
    }
    data[pos] = Pair(elem, rank);
    size++;
}

Pair Vector::pop_back() {
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
    Pair* ptr = new Pair[capacity * 2];
    for (int i = 0;i < size;i++) {
        ptr[i] = data[i];
        //std::cout << "//" << ptr[i] << std::endl;
    }
    free();
    capacity *= 2;
    data = ptr;
}

int Vector::getElementWithBiggestRank() {
    return pop_back().value;
}

int Vector::peak() const {
    return data[size - 1].value;
}

#endif