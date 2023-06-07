#include <iostream>
using namespace std;

template<class T,size_t size>
class Array
{
public:
	Array(T* other);
	const T& operator[](size_t index)const;
	T& operator[](size_t index);
private:
	T array[size];
};
template<class T, size_t size>
Array<T,size>::Array(T other[size])
{
	for (int i = 0; i < size < i++)
	{
		array[i] = other[i];
	}
}
template<class T, size_t size>
T& Array<T, size>::operator[](size_t index)
{
	return array[index];
}
template<class T, size_t size>
const T& Array<T, size>::operator[](size_t index) const
{
	return  array[index];
}


int main()
{
	Array<int, 10> arr;
	arr[0] = 5;
}
