#include <iostream>
#include <fstream>

int countCertainDigits(std::ifstream& file)
{
	int count = 0;
	while (!file.eof())
	{
		if (file.get() != 'a' || file.get() != 'd') count++;
	}

	file.close();
	return count;
}


int main()
{
	std::ifstream file("diffLetters.txt");

	if (!file.is_open())
	{
		std::cout << "Error" << std::endl;
		return -1;
	}

	std::cout << countCertainDigits(file) << std::endl;

	file.close();
}
