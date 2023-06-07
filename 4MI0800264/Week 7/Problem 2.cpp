#include <iostream>

template<typename Т>
class vector {
public:

    vector()
    {
        size = 0;
        capacity = 8;
        data = new Т[capacity]{ 0 };
    }

    vector(const vector& source)
    {
        copy(source);
    }

    vector(vector&& source) noexcept
    {
        size = source.size;
        capacity = source.capacity;
        data = source.data;
        source.data = nullptr;
        source.size = 0, source.capacity = 0;
    }

    vector& operator=(const vector& source)
    {
        if (this != &source)
        {
            free();
            copy(source);
        }
        return *this;
    }

    vector(int argCap)
    {
        size = 0;
        capacity = argCap;
        data = new Т[capacity]{ 0 };
    }

    vector(int argCap, Т argDef)
    {
        size = 0;
        capacity = argCap;
        data = new Т[capacity]{ argDef };
    }

    Т operator[](size_t index) const
    {
        return data[index];
    }

    Т& operator[](size_t index)
    {
        return data[index];
    }

    void push_back(Т element)
    {
        if (size > capacity)
            resize();

        data[size++] = element;
    }

    Т pop_back()
    {
        Т last = data[size--];
        return last;
    }

    ~vector()
    {
        std::cout << "Destruction" << std::endl;
        delete[] data;
    }

private:
    Т* data;
    size_t size;
    size_t capacity;

    void free()
    {
        delete[] data;
    }

    void copy(const vector& source)
    {
        size = source.size;
        capacity = source.capacity;
        data = source.data;
    }

    void resize()
    {
        Т* newData = new Т[capacity * 2];

        for (size_t i = 0; i < size; i++)
        {
            newData[i] = data[i];
        }

        free();

        data = newData, capacity *= 2;
    }
};
