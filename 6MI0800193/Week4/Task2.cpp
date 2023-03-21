#include <iostream>
#include<exception>

struct pair
{
    int val;
    size_t rank;
};

class priority_vector {
public:
    priority_vector();

    priority_vector(const priority_vector&);
    priority_vector(priority_vector&&);

    priority_vector& operator=(const priority_vector&);

    priority_vector(int argCap);

    void enqueue(int elem, size_t rank);

    int getElementWithBiggestRank();

    int peak() const;

    pair operator[](size_t) const;

    size_t get_size();

    ~priority_vector();
private:
    pair* data;    
    size_t size;     
    size_t capacity;

    void free();

    void copy(const priority_vector&);

    void resize();

    void sort();

    bool valid_index(size_t index) const
    {
        return index >= 0 && index < size;
    }
};

priority_vector::priority_vector(int argCap)
{
    capacity = argCap;
    size = 0;
    data = new pair[capacity];
}

size_t priority_vector::get_size()
{
    return this->size;
}

priority_vector::priority_vector() : priority_vector(8)
{
}

priority_vector::priority_vector(const priority_vector& from)
{
    this->capacity = from.capacity;
    this->size = from.size;

    this->data = new pair[this->capacity];
    this->copy(from);

}

priority_vector::priority_vector(priority_vector&& to_get)
{
    this->capacity = to_get.capacity;
    this->size = to_get.size;

    this->data = to_get.data;
    to_get.data = nullptr;
}

priority_vector::~priority_vector()
{
    this->size = 0;
    this->capacity = 0;
    this->free();
}

priority_vector& priority_vector::operator=(const priority_vector& right_side)
{
    if (this != &right_side)
    {
        free();
        this->capacity = right_side.capacity;
        this->size = right_side.size;

        this->data = new pair[this->capacity];
        this->copy(right_side);
    }
    return *this;
}

pair priority_vector::operator[](size_t pos) const
{
    if (!this->valid_index(pos))
        throw std::invalid_argument("invalid index");

    return this->data[pos];
}

void priority_vector::free()
{
    delete[] this->data;
}

void priority_vector::sort()
{
    int i, j, min_idx;
    for (i = 0; i < size - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < size; j++)
        {
            if (data[j].rank < data[min_idx].rank)
                min_idx = j;
        }
        if (min_idx != i)
            std::swap(data[min_idx], data[i]);
    }
}

void priority_vector::copy(const priority_vector& from)
{
    for (size_t i = 0; i < from.size; i++)
    {
        this->data[i] = from.data[i];
    }
}

void priority_vector::enqueue(int val, size_t rank)
{
    if (this->size == this->capacity)
        this->resize();

    this->data[this->size] = { val, rank };
    this->size++;
    this->sort();
}

int priority_vector::peak() const
{
    return this->data[this->size - 1].val;
}

int priority_vector::getElementWithBiggestRank()
{
    if (this->size == 0)
        throw std::out_of_range("out");

    this->size--;
    int val = this->data[this->size].val;
    this->data[this->size] = { 0,0 };
    return val;
}

void priority_vector::resize()
{
    pair* old_data = this->data;
    this->capacity *= 2;
    this->data = new pair[capacity];

    for (size_t i = 0; i < this->size; i++)
    {
        this->data[i] = old_data[i];
    }

    delete[] old_data;
}
int main()
{
    priority_vector test;

    test.enqueue(6, 1);
    test.enqueue(2, 1);
    test.enqueue(4, 1);
    test.enqueue(8, 2);
    test.enqueue(3, 2);
    test.enqueue(4, 3);
    test.enqueue(1, 2);
    test.enqueue(8, 2);

    std::cout << test.peak() << std::endl;
    std::cout << std::endl;

    std::cout << test.getElementWithBiggestRank() << std::endl;
    std::cout << std::endl;

    for (size_t i = 0; i < test.get_size(); i++)
    {
        std::cout << test[i].val << ", " << test[i].rank << std::endl;
    }

}