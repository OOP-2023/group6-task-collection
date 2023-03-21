#include <iostream>

class Pair
{
public:
    int element;
    size_t rank;    
};

class vector
{
private:
    Pair* data;
    size_t size;
    size_t capacity;
    void resize()
    {
        Pair* newData = new Pair[capacity*2];
        for (size_t i = 0; i < capacity; i++)
        {
            newData[i].element = data[i].element;
            newData[i].rank = data[i].rank;
        }
        setCapacity(capacity * 2);
        delete[] data;
        data = newData;
    }
    void free() 
    {
        delete[capacity] data;
    }
    void copy(const vector& vectorCpy) 
    {
        size = vectorCpy.size;
        setCapacity(vectorCpy.capacity);
        data = new Pair[capacity];

        for (size_t i = 0; i < size; i++)
        {
            data[i].element = vectorCpy.data[i].element;
            data[i].rank = vectorCpy.data[i].rank;
        }
    }

public:
    vector()
    {
        size = 0;
        capacity = 8;
        data = new Pair[capacity];
    }
    vector(int argCap)
    {
        size = 0;
        setCapacity(argCap);
        data = new Pair[capacity];
    }
    vector(int argCap, int argDef)
    {
        size = 0;
        setCapacity(argCap);
        data = new Pair[capacity];
        for (size_t i = 0; i < capacity; i++)
        {
            data[i].element = argDef;
            data[i].rank = 0;
        }
    }
    ~vector() 
    {
        delete[capacity] data;
    }
    vector(const vector& vectorCpy)
    {
        copy(vectorCpy);
    }
    vector(vector&& vectorObj)
    {
        size = vectorObj.size;
        setCapacity(vectorObj.capacity);
        data = vectorObj.data;
        vectorObj.size = 0;
        vectorObj.capacity = 0;
        vectorObj.data = nullptr;
    }
    vector& operator=(const vector& vectorObj)
    {
        if (this != &vectorObj)
        {
            free();
            copy(vectorObj);
        }

        return *this;
    }
    //-----------------------------------------------
    Pair* getPairs()
    {
        return data;
    }
    size_t getSize()
    {
        return size;
    }
    size_t getCapacity()
    {
        return capacity;
    }

    void setCapacity(size_t cap)
    {
        if (cap < 8)
        {
            capacity = 0;
        }
        else capacity = cap;
    }
    //-----------------------------------------------

    void push_back(int number, size_t _rank)
    {
        if (size == capacity) resize();
        data[size].element = number;
        data[size].rank = _rank;
        size++;
    }

    int getElementWithBiggestRank()
    {
        int maxRank = data[0].rank;
        int removedNumber = data[0].element;
        int maxIndex = 0;
        for (size_t i = 1; i < size; i++)
        {
            if (maxRank < data[i].rank)
            {
                maxRank = data[i].rank;
                removedNumber = data[i].element;
                maxIndex = i;
            }
        }
        for (size_t i = maxIndex; i < size; i++)
        {
            data[i].element = data[i + 1].element;
            data[i].rank = data[i + 1].rank;
        }

        size--;
        return removedNumber;
    }

    int peak() const
    {
        int elemWithBiggestRank = data[0].element;
        int maxRank = data[0].rank;
        for (size_t i = 1; i < size; i++)
        {
            if (maxRank < data[i].rank)
            {
                maxRank = data[i].rank;
                elemWithBiggestRank = data[i].element;
            }
        }

        return elemWithBiggestRank;
    }
};


int main()
{
    vector v(10);

    for (size_t i = 0; i < 10; i++)
    {
        v.push_back(i + rand(), rand());
    }
    for (size_t i = 0; i < v.getSize(); i++)
    {
        std::cout<< v.getPairs()[i].element <<" " <<v.getPairs()[i].rank<< std::endl;
    }
    std::cout << std::endl;
    std::cout << v.peak() << std::endl;
    std::cout<<v.getElementWithBiggestRank() << std::endl;
    std::cout << std::endl;
    for (size_t i = 0; i < v.getSize(); i++)
    {
        std::cout << v.getPairs()[i].element << " " << v.getPairs()[i].rank << std::endl;
    }


}