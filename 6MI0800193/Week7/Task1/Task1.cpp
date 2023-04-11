#include <iostream>
using namespace std;

template<typename T>
const T& max(T* arr, const size_t count)
{
	T max = arr[0];
	int j = 0;
	for (size_t i = 1; i < count; i++)
	{
		if (max < arr[i])
		{
			max = arr[i];
			j = i;
		}
	}
	return arr[j];
}

int main()
{
	int arr[] = { 1,2,6,8,3,1 };

	int max_arr = max(arr, 6);

	cout << max_arr << endl;

	char arr2[] = { 'a', 'b', 'C', 'W', 'z' };

	char max_arr2 = max(arr2, 5);

	cout << max_arr2 << endl;
}
