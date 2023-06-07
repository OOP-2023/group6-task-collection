#include <iostream>
template <typename T>

T findMaxs(const T* arr, size_t size)
{
	T maxNumber = arr[0];
	for (size_t i = 1; i < size; i++)
		if (maxNumber < arr[i])
			maxNumber = arr[i];

	return maxNumber;
}

int main()
{
	int arr[] = { 1,5,10,12,32 };
	double arr1[] = { 1,10.5,2,20.5,5.32 };
	unsigned arr2[] = { 5,10,102,4,2 };
	char arr3[] = { 'b','d','a','z','c' };

	std::cout << findMaxs(arr, 5)<<std::endl;
	std::cout<<findMaxs(arr1, 5)<<std::endl;
	std::cout << findMaxs(arr2, 5) << std::endl;
	std::cout << findMaxs(arr3, 5) << std::endl;
}
