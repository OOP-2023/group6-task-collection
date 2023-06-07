#include <iostream>

template<typename T>
const T& max(const T* arr, size_t size)
{
	if (size < 1)
		throw std::runtime_error("Empty array! \n");

	T max;

	for (size_t i = 0; i < size; i++)
	{
		max = (arr[i] > max) ? arr[i] : max;
	}

	return max;
}

