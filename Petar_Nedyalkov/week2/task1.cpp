#include <iostream>
#include <fstream>

int main()
{
	std::ofstream file("result.txt");

	if (!file.is_open())
	{
		std::cout << "Error!" << std::endl;
		return -1;
	}

	int a, b, c;
	int sum = 0, multi = 1;
	std::cin >> a >> b >> c;
	sum = a + b + c;
	multi = a * b * c;

	file << sum << " " << multi << std::endl;
	file.close();
	
	std::ifstream fileO("result.txt");

	if(!fileO.is_open())
	{
		std::cout << "Error!" << std::endl;
		return -1;
	}
	int firstNumber, secondNumber;
	fileO >> firstNumber >> secondNumber;

	std::cout << firstNumber - secondNumber << std::endl;

	fileO.close();
}
