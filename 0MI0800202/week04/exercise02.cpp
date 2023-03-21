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
        arr[0].value = -10000;
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
    }
    void enqueue(int value)
    {
        for (int i = 0; i < currentSize; ++i)
        {
            if(arr[i].value < value)
            {
                insert(value, i);
            }
        }

    }
}

