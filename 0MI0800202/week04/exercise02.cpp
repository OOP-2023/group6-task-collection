#include <iostream>

const int MAX_SIZE = 128;
class Pair{
public:
    int value, rank;
};
class PriorityVector
{
private:
    Pair* arr;
    int currentSize, capacity;
public:
    PriorityVector()
    {
        currentSize = 1;
        capacity = MAX_SIZE;
        arr = new Pair[capacity];
        arr[0].value = 0;
        arr[0].rank = 0;
    }
    Pair* getArr()
    {
        return arr;
    }
    int getSize()
    {
        return currentSize;
    }
    void shift(int firstIndex, int secondIndex)
    {
        arr[secondIndex] = arr[firstIndex];
    }
    void insert(int value, int index)
    {
        for (int i = currentSize; i > index; i--)
        {
            shift(i - 1, i);
        }
        arr[index].value = value;
        arr[index].rank = index;
        currentSize++;
    }
    void enqueue(int value)
    {
        for (int i = 0; i < currentSize; ++i)
        {
            if(arr[i].value < value)
            {
                insert(value, i);
                break;
            }
        }

    }
    Pair dequeue()
    {
        Pair result = arr[0];
        for (int i = 0; i < currentSize; ++i)
        {
            shift(i + 1, i);
        }
        return result;
    }
    int peak() const
    {
        return arr[0].value;
    }
    ~PriorityVector()
    {
        delete[] arr;
    };
};

int main()
{
    PriorityVector vector = PriorityVector();
    vector.enqueue(14);
    vector.enqueue(15);
    vector.enqueue(16);
    vector.enqueue(17);
    vector.enqueue(12);
    vector.enqueue(12);
    vector.enqueue(18);
    vector.enqueue(12);
    vector.enqueue(12);

    std::cout << vector.dequeue().value << "\n";
    Pair* pairPtr = vector.getArr();
    for (int i = 0; i < vector.getSize(); ++i)
    {
        std::cout << vector.peak();
    }

}