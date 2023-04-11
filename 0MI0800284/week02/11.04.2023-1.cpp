#include <iostream>
#include "Source.cpp"
using namespace std;

template<class T>
const T& max(T* array, size_t size)
{
	if (size < 1)
		throw "Error";
	size_t index = 0;
	for (size_t i = 1; i < size; i++)
	{
		if (array[index] < array[i])
			index = i;
	}
	return array[index];
}
int main()
{
	int arr[] = { 1,2,5,4,7,8,1,21 };
	cout << max(arr, 9);

	double arr1[] = { 1,2,5,4,7,8,1,21 };
	cout << max(arr1, 9);
}
