#include <iostream>
#include "MyArray.hpp"

int main()
{
    Array<char, 10> arr;
	size_t j = 0;

	for (size_t i = 'A'; i < 'J'; i++)
	{
		arr.add(i);
	}

	for (size_t i = 0; i < arr.get_count(); i++)
	{
		std::cout << arr[i] << std::endl;
	}

	std::cout << "Front: " << arr.front() << " Back: " << arr.back() << std::endl;
}
