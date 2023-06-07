#include <iostream>
#include<exception>

template<class T>
class vector {
public:
    /// @brief Създава празен контейнер с capacity 8.
    vector();

    vector(const vector<T>&);
    vector(vector<T>&&);

    vector<T>& operator=(const vector<T>&);

    /// @brief Създава контейнер.
    /// @param argCap големината на контейнера.
    vector(int argCap);

    /// @brief Създава контейнер.
    /// @param argCap Големината на контейнера.
    /// @param argDef Началната стойност на всички елементи.
    vector(int argCap, const T& argDef); // Създава контейнер с argCap големина като всеки елемент е равен на argDef.

    /// @brief Връща число на дадена позиция.
    /// @param  Позицията от която искаме да четем.
    const T& operator[](size_t) const;

    /// @brief Връща число на подадена позиция и позволява промяната му.
    /// @param  Позицията от която да четем или в която да пишем
    T& operator[](size_t);

    /// @brief Добавя елемент в колекцията.
    /// @param  Елемента, който добавяме.
    void push_back(const T&);

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
    T* data;       // < Паметта, в която държим информацията
    size_t size;     // < Броя елементи в колекцията
    size_t capacity; // < Максималния брой елементи, които колекцията поддържа

    /// @brief Изтрива паметта
    void free();

    /// @brief Копира обект
    void copy(const vector<T>&);

    /// @brief Удвоява размера на обекта. 
    void resize();

    bool valid_index(size_t index) const
    {
        return index >= 0 && index < size;
    }
};

template<typename T>
vector<T>::vector(int argCap)
{
    capacity = argCap;
    size = 0;
    data = new T[capacity];
}

template<typename T>
vector<T>::vector(int argCap, const T& argDef) : vector(argCap)
{
    this->size = argCap;
    for (size_t i = 0; i < argCap; i++)
    {
        data[i] = argDef;
    }
}

template<typename T>
vector<T>::vector() : vector(8)
{
}

template<typename T>
vector<T>::vector(const vector<T>& from)
{
    this->capacity = from.capacity;
    this->size = from.size;

    this->data = new T[this->capacity];
    this->copy(from);

}

template<typename T>
vector<T>::vector(vector<T>&& to_get)
{
    this->capacity = to_get.capacity;
    this->size = to_get.size;

    this->data = to_get.data;
    to_get.data = nullptr;
}

template<typename T>
vector<T>::~vector()
{
    this->size = 0;
    this->capacity = 0;
    this->free();
}

template<typename T>
vector<T>& vector<T>::operator=(const vector<T>& right_side)
{
    if (this != &right_side)
    {
        free();
        this->capacity = right_side.capacity;
        this->size = right_side.size;

        this->data = new T[this->capacity];
        this->copy(right_side);
    }
    return *this;
}

template<typename T>
void vector<T>::free()
{
    delete[] this->data;
}

template<typename T>
void vector<T>::copy(const vector<T>& from)
{
    for (size_t i = 0; i < from.size; i++)
    {
        this->data[i] = from.data[i];
    }
}

template<typename T>
const T& vector<T>::operator[](size_t pos) const
{
    if (!this->valid_index(pos))
        throw std::invalid_argument("invalid index");

    return this->data[pos];
}

template<typename T>
T& vector<T>::operator[](size_t pos)
{
    if (!this->valid_index(pos))
        throw std::invalid_argument("invalid index");

    return this->data[pos];
}

template<typename T>
void vector<T>::push_back(const T& val)
{
    if (this->size == this->capacity)
        this->resize();

    this->data[this->size] = val;
    this->size++;
}

template<typename T>
int vector<T>::pop_back()
{
    if (this->size == 0)
        throw std::out_of_range("out");

    this->size--;
    int val = this->size;
    this->data[this->size] = 0;
    return val;
}

template<typename T>
void vector<T>::resize()
{
    T* old_data = this->data;
    this->capacity *= 2;
    this->data = new T[capacity];

    for (size_t i = 0; i < this->size; i++)
    {
        this->data[i] = old_data[i];
    }

    delete[] old_data;
}

template<typename T>
int vector<T>::get_capacity() const
{
    return this->capacity;
}

template<typename T>
int vector<T>::get_size() const
{
    return this->size;
}

template<typename T>
void fill_vector(vector<T>& vec, int start, int end)
{
    for (T i = start; i <= end; i++)
    {
        vec.push_back(i);
    }
}

template<typename T>
void print_vector(const vector<T>& vec)
{
    for (size_t i = 0; i < vec.get_size(); i++)
    {
        std::cout << vec[i] << " " << vec.get_size() << std::endl;
    }
    std::cout << std::endl;
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const vector<T>& vec)
{
    for (size_t i = 0; i < vec.get_size(); i++)
    {
        out << vec[i] << ' ';
    }
    out << std::endl;
    return out;
}

int main()
{
    vector<int> test;
    fill_vector<int>(test, 1, 19);
    std::cout << test;


    vector<char> test2;
    fill_vector<char>(test2, 'A', 'H');
    std::cout << test2;



}
