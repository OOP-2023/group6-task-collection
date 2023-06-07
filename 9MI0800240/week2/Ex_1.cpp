// 07_03.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;

int read_number(ifstream& file)
{
	int result;
	file >> result;
	return result;
}

int sumOfThirdNumber(int a, int b, int c)
{
	return a + b + c;
}

int prodOfThirdNumber(int a, int b, int c)
{
	return a * b * c;
}

int difference(int a, int b)
{
	return a - b;
}
int main()
{
    ofstream file("MyFile.txt");

	if (!file.is_open())
	{
		cout << "Error!" << endl;
		return -1;
	}

	int a, b,c;
	cin >> a >> b >> c;

	cout << "The sum is:" << sumOfThirdNumber(a, b, c);
	cout << "The prod is:" << prodOfThirdNumber(a,b,c);

	int sum = sumOfThirdNumber(a, b, c);
	int prod = prodOfThirdNumber(a, b, c);

	file << sum << prod;


	file.close();

	ifstream inFile("MyFile.txt");

	if (!file.is_open())
	{
		cout << "Error!" << endl;
		return 0;
	}
	int numOne=read_number(inFile);
	int numTwo=read_number(inFile);
	cout << "The difference is: " << difference(numOne, numTwo);

	inFile.close();

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
