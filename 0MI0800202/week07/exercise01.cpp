#include <iostream>

template<typename T>

const T& max(T* arr, size_t size)
{
    size_t idx = 0;
    for (int i = 1; i < size; ++i)
    {
        if (arr[idx] < arr[i])
        {
            idx = i;
        }
    }
    return arr[idx];
}
