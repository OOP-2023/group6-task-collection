#include <iostream>
using namespace std;

struct Pair
{
	int value;
	size_t rank;
};

/// @brief Клас, който представлява
/// динамичен масив
class vector {
public:
    /// @brief Създава празен контейнер с capacity 8.
    vector()
    {
        size = 0;
        capacity = 8;
        data = new Pair[capacity] {0};
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

    /// @brief Създава контейнер.
    /// @param argCap големината на контейнера.
    vector(int argCap)
    {
        size = 0;
        capacity = argCap;
        data = new Pair [capacity] {0};
    }

    /// @brief Създава контейнер.
    /// @param argCap Големината на контейнера.
    /// @param argDef Началната стойност на всички елементи.
    vector(int argCap, Pair argDef) // Създава контейнер с argCap големина като всеки елемент е равен на argDef.
    {
        size = 0;
        capacity = argCap;
        data = new Pair[capacity] {argDef};
    }
    /// @brief Връща число на дадена позиция.
    /// @param  Позицията от която искаме да четем.
    Pair operator[](size_t index) const
    {
        return data[index];
    }

    /// @brief Връща число на подадена позиция и позволява промяната му.
    /// @param  Позицията от която да четем или в която да пишем
    Pair& operator[](size_t index)
    {
        return data[index];
    }

    /// @brief Добавя елемент в колекцията.
    /// @param  Елемента, който добавяме.
    void push_back(Pair element)
    {
        if (size > capacity)
            resize();

        data[size++] = element;
    }

    /// @brief Премахва последния елемент от колекцията
    /// @return Последния елемент от колекцията
    Pair pop_back()
    {
        return data[size--];
    }

    ~vector()
    {
        cout << "Destruction" << endl;
        delete[capacity] data;
    }


    size_t getCapacity()
    {
        return capacity;
    }
    void setCapacity(size_t value)
    {
        capacity = value;
    }
    size_t getSize()
    {
        return size;
    }
    void setSize(size_t value)
    {
        size = value;
    }

    size_t getLastValue() const
    {
        return data[size].value;
    }

private:
    Pair* data;       // < Паметта, в която държим информацията
    size_t size;     // < Броя елементи в колекцията
    size_t capacity; // < Максималния брой елементи, които колекцията поддържа

    /// @brief Изтрива паметта
    void free()
    {
        delete[capacity] data;
    }

    /// @brief Копира обект
    void copy(const vector& source)
    {
        size = source.size;
        capacity = source.capacity;
        data = source.data;
    }

    /// @brief Удвоява размера на обекта. 
    void resize()
    {
        Pair* newData = new Pair[capacity * 2];

        for (size_t i = 0; i < size; i++)
        {
            newData[i] = data[i];
        }

        free(); // delete[capacity] data;

        data = newData, capacity *= 2;
    }
};


class priorityVector
{
private:
    vector data;

    void bubbleSortVector()
    {
        size_t size = data.getSize();
        bool wasSwapped = false;
        for (size_t i = size-1; i >1; i--)
        {
            wasSwapped = false;
            for (size_t j = i; j >1; j--)
            {
                if (data[j].rank < data[j - 1].rank)
                {
                    swap(data[j], data[j - 1]);
                    wasSwapped = true;
                }
            }

            if (!wasSwapped)
                return;
        }
    }
public:

    priorityVector()
    {
        vector data;
    }

    ~priorityVector()
    {
        data.~vector();
    }




    void enqueue(int value, size_t rank)
    {
        Pair newPair{ value,rank };
        data.push_back(newPair);
        this->bubbleSortVector();
    }

    int peak() const
    {
        return data.getLastValue();
    }

    int dequeue()
    {
        int heaviest = this->peak();
        data.pop_back();
        return heaviest;
    }

    int getElementWithBiggestRank()
    {
        return data[data.getSize()].rank;
    }
};


int main()
{

	return 0;
}