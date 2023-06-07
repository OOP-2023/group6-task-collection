#include <iostream>
template <typename T, const size_t size>

class MyArray {
private:
	T memoryBlock[size];
public:
	const T operator[](size_t index) const
	{
		if (index >= size)
			throw std::exception("Invalid argument");

		return memoryBlock[index];
	}
	T& operator[](size_t index)
	{
		if (index >= size)
			throw std::exception("Invalid argument");

		return memoryBlock[index];
	}
	const size_t getSize() const
	{
		return size;
	}

};

int main()
{
	MyArray<int, 5> arr;
	size_t size = arr.getSize();

	for (int i = 0; i < size; i++)
		std::cin >> arr[i];


	for (int i = 0; i < size; i++)
		std::cout << arr[i] << " ";

	std::cout << std::endl;
}