#include <iostream>
using namespace std;

struct VectorPair
{
    int element;
    size_t rank;
};

void swap(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}

int getBiggestEl(int* arr,size_t sizeOfArr)
{
    int biggest = -1;
    for (size_t i = 0; i < sizeOfArr; i++)
    {
        if (arr[i]>biggest)
        {
            biggest = arr[i];
        }
    }
    return biggest;
}


class priorityVector {
    int size;
    int capacity;
    VectorPair* data = new VectorPair[capacity];


public:

    void resize() {
        capacity = 2 * capacity;

        VectorPair* newMemory = new VectorPair[capacity];

        for (int i = 0; i < size; i++)
        {
            newMemory[i].element = data[i].element;
            newMemory[i].rank = data[i].rank;
        }

        delete[] data;
        data = newMemory;
    }

    void enqueue(int elem, size_t rank)
    {
        if (size==capacity)
        {
            resize();
        }
        data[size++].element = elem;
        data[size++].rank = rank;
    }

  
    //int peak() const
    //{
    //    return getBiggestEl()
    //}

    
    int dequeue();

private:
    
};



int main()
{

}
