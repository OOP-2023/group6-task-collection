#include <iostream>
using namespace std;

template<class T>
const T& max(T* arr, size_t size) {
	if (size == 0)
		throw exception();

	int maxIndex = 0;
	for (int i = 1; i < size; i++)
	{
		if (arr[maxIndex] < arr[i])
		{
			 arr[maxIndex] = arr[i];
		}
	}
	return arr[maxIndex];
}
