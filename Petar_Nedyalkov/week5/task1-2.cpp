#include <iostream>
#include <fstream>
#include <string.h>
#pragma warning (disable : 4996);

struct Example {
	int data;
	char buff[8];

	void print()
	{
		std::cout << data << " " << buff << std::endl;
	}
};

void writeIntoFile(const char* fileName,const Example* examples ,unsigned& number)
{
	std::ofstream myFile(fileName, std::ios::out | std::ios::app | std::ios::binary);

	for (size_t i = 0; i < number; i++)
		myFile.write((char*)&examples[i], sizeof(examples[i]));

	myFile.close();
}

size_t examplesInFile(const char* fileName)
{
	unsigned count = 0;
	std::ifstream myFile(fileName, std::ios::in | std::ios::binary);
	while (true)
	{
		Example ex;
		myFile.read((char*)&ex, sizeof(ex));
		if (myFile.eof()) break;

		count++;
	}

	myFile.close();
	return count;
}

Example exampleWithPattern(const char* fileName, const char* pattern)
{
	Example ex;
	std::ifstream myFile(fileName, std::ios::in | std::ios::binary);
	while (true)
	{
		myFile.read((char*)&ex, sizeof(ex));
		if (myFile.eof()) break;

		if (strcmp(ex.buff, pattern) == 0)
		{
			myFile.close();
			return ex;
		}
	}

	ex.data = -1;
	strcpy(ex.buff,"err");
	myFile.close();

	return ex;

}

int main()
{
	unsigned int n;
	std::cin >> n;
	Example* examples = new Example[n];
	for (unsigned i = 0; i < n; i++)
	{
		std::cin >> examples[i].data;
		std::cin.getline(examples[i].buff, 8, '\n');
		//std::cin.ignore();
	}
	
	writeIntoFile("myFile.txt", examples, n);
	std::ifstream myFile("myFile.txt", std::ios::in);
	

	//Just seeing what is in the file
	Example ex;
	while (true)
	{
		myFile.read((char*)&ex,sizeof(ex));
		if (myFile.eof()) break;
		std::cout << ex.data << " " << ex.buff << std::endl;
	}

	std::cout << examplesInFile("myFile.txt")<<std::endl;
	exampleWithPattern("myFile.txt", "Iran").print();
	myFile.close();
	delete[] examples;
}
