#include <iostream>
#include<exception>

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

    /// @brief Връща големината на контейнера
    /// @return Големината на контейнера
    int get_capacity() const;

    /// @brief Връща броя на елементите в контейнера
    /// @return Броя на елементите
    int get_size() const;

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

    bool valid_index(size_t index) const
    {
        return index >= 0 && index < size;
    }
};

//Constructors
vector::vector(int argCap)
{
    capacity = argCap;
    size = 0;
    data = new int[capacity];
}

vector::vector(int argCap, int argDef) : vector(argCap)
{
    this->size = argCap;
    for (size_t i = 0; i < argCap; i++)
    {
        data[i] = argDef;
    }
}

vector::vector() : vector(8)
{
}

vector::vector(const vector& from)
{
    this->capacity = from.capacity;
    this->size = from.size;

    this->data = new int[this->capacity];
    this->copy(from);

}

vector::vector(vector&& to_get)
{
    this->capacity = to_get.capacity;
    this->size = to_get.size;

    this->data = to_get.data;
    to_get.data = nullptr;
}

vector::~vector()
{
    this->size = 0;
    this->capacity = 0;
    this->free();
}

vector& vector::operator=(const vector& right_side)
{
    if (this != &right_side)
    {
        free();
        this->capacity = right_side.capacity;
        this->size = right_side.size;

        this->data = new int[this->capacity];
        this->copy(right_side);
    }
    return *this;
}

void vector::free()
{
    delete[] this->data;
}

void vector::copy(const vector& from)
{
    for (size_t i = 0; i < from.size; i++)
    {
        this->data[i] = from.data[i];
    }
}

int vector::operator[](size_t pos) const
{
    if (!this->valid_index(pos))
        throw std::invalid_argument("invalid index");

    return this->data[pos];
}

int& vector::operator[](size_t pos)
{
    if (!this->valid_index(pos))
        throw std::invalid_argument("invalid index");

    return this->data[pos];
}

void vector::push_back(int val)
{
    if (this->size == this->capacity)
        this->resize();

    this->data[this->size] = val;
    this->size++;
}

int vector::pop_back()
{
    if (this->size == 0)
        throw std::out_of_range("out");

    this->size--;
    int val = this->size;
    this->data[this->size] = 0;
    return val;
}

void vector::resize()
{
    int* old_data = this->data;
    this->capacity *= 2;
    this->data = new int[capacity];

    for (size_t i = 0; i < this->size; i++)
    {
        this->data[i] = old_data[i];
    }
    
    delete[] old_data;
}

int vector::get_capacity() const
{
    return this->capacity;
}

int vector::get_size() const
{
    return this->size;
}

int main()
{
    vector test;
    for (size_t i = 0; i < 18; i++)
    {
        test.push_back(i);
    }
    std::cout << test.get_size() << " " << test.get_capacity() << std::endl;
    for (size_t i = 0; i < test.get_size(); i++)
    {
        std::cout << test[i] << " " << test.get_size() << std::endl;
    }

    vector test2(test);
    test2.pop_back();
    test2.pop_back();
    test2.pop_back();
    test2.pop_back();
    
    std::cout << std::endl;
    std::cout << test2.get_size() << " " << test2.get_capacity() << std::endl;
    for (size_t i = 0; i < test2.get_size(); i++)
    {
        std::cout << test2[i] << " " << test2.get_size() << std::endl;
    }
    
}