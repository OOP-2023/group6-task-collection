
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

	int a, b, c;
	cin >> a >> b >> c;

	cout << "The sum is:" << sumOfThirdNumber(a, b, c);
	cout << "The prod is:" << prodOfThirdNumber(a, b, c);

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
	int numOne = read_number(inFile);
	int numTwo = read_number(inFile);
	cout << "The difference is: " << difference(numOne, numTwo);

	inFile.close();

}
