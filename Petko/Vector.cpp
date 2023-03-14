#ifndef VECTOR_HEADER
#define VECTOR_HEADER

/// @brief Клас, който представлява
/// динамичен масив
class vector {
public:
    /// @brief Създава празен контейнер с capacity 8.
    vector();

    vector(const vector&);
    vector(vector&&);

    vector& operator=(const vector&);

    /// @brief Създава контейнер.
    /// @param argCap големината на контейнера.
    vector(int argCap);

    /// @brief Създава контейнер.
    /// @param argCap Големината на контейнера.
    /// @param argDef Началната стойност на всички елементи.
    vector(int argCap, int argDef); // Създава контейнер с argCap големина като всеки елемент е равен на argDef.

    /// @brief Връща число на дадена позиция.
    /// @param  Позицията от която искаме да четем.
    int operator[](size_t) const;

    /// @brief Връща число на подадена позиция и позволява промяната му.
    /// @param  Позицията от която да четем или в която да пишем
    int& operator[](size_t);

    /// @brief Добавя елемент в колекцията.
    /// @param  Елемента, който добавяме.
    void push_back(int);

    /// @brief Премахва последния елемент от колекцията
    /// @return Последния елемент от колекцията
    int pop_back();

    ~vector();
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

vector::vector() : vector(8) {}

vector::vector(int argCap) {
    this->size = 0;
    this->capacity = argCap;
    this->data = new int[this->capacity];
}
vector::vector(int argCap, int argDef)
{
    this->size = 0;
    this->capacity = argCap;
    this->data = new int[this->capacity];
    for (int i = size; i < capacity; i++)
    {
        this->data[i] = argDef;
    }
}
int vector::pop_back() {
    this->data[size] = 0;
    this->size--;
}
void vector::free() {
    delete[] data;
}
void vector::resize()
{
    this->capacity *= 2;
    this->data = new int[this->capacity];
}
void vector::copy(const vector& other) {
    this->size = other.size;
    this->capacity = other.capacity;
    this->data = new int[this->capacity];
    for (size_t i = 0; i < other.size; i++) {
        this->data[i] = other[i];
    }
}
int vector::operator[](size_t pos)const {
            return this->data[pos];
}
int& vector::operator[](size_t pos) {
    return this->data[pos];
}
void vector::push_back(int el) {
    if (this->size == this->capacity)
        resize();
    this->data[size] = el;
    this->size++;
}
vector::~vector() {
    free();
}

vector::vector(vector&& other) {
    this->data = other.data;
    this->size = other.size;
    this->capacity = other.capacity;

    other.size = 0;
    other.capacity = 0;
    other.data = nullptr;
}

vector::vector(const vector& other) {
    copy(other);
}

vector& vector::operator=(const vector& other) {
    if (this != &other) {
        free();
        copy(other);
    }
    return *this;
}

#endif

