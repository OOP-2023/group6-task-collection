#include <iostream>

template<typename T, size_t size>
class MyArr
{
public:
    T arr[size];
    T &operator=(const T& other);

    const size_t length() const
    {
        return size;
    }
};



template<typename T, size_t size>
T &MyArr<T, size>::operator=(const T &other)
{
    for (int i = 0; i < size; ++i)
    {
        arr[i] = other.arr[i];
    }
}

int main()
{
    MyArr<int, 5> arr;
    MyArr<int, 6> arr2;
    for (int i = 0; i < arr.length(); ++i)
    {
        arr.arr[i] = arr2.arr[i];
        std::cout << arr.arr[i];
    }

}