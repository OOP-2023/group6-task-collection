#include <iostream>

template<typename T>
const T& max(T* arr, size_t size)
{
	if (size == 0)
		throw std::exception();
	size_t maxIndex = 0;
	for (size_t i = 1; i < size; i++)
	{
		if (arr[maxIndex] < arr[i])
			arr[maxIndex] = arr[i];
	}
	return arr[maxIndex];
}

//int main()
//{
//	int* arr = new int[10];
//
//	for (size_t i = 0; i < 10; i++)
//	{
//		arr[i] = rand();
//	}
//
//	std::cout << max<int>(arr, 10);
//}