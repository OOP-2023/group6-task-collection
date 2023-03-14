#include <iostream>
#include <fstream>
#include<assert.h>


int main()
{
	std::ofstream file("result.txt");

	if (!file.is_open()) {
		std::cout << "Error!" << std:: endl;
		return -1;
	}


	int a, b, c;
	std::cout << "Enter numbers a, b, c :" << std::endl;
	std::cin >> a >> b >> c;
	file << a + b + c << " " << a * b * c << std::endl;

	if (!file.eof()) {
		std::cout << "The file contains more data!" << std::endl;
	}
	file.close();
}



