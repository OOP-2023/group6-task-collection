// Zad1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;
void readFile()
{
	int sum,pr;
	ifstream file("result.txt");
	file >> sum >> pr;
	cout << pr - sum;
}
int main()
{
	ofstream file("result.txt");
	if (!file.is_open())
	{
		cout << "Error!";
		return -1;
	}
	int a, b, c;
	cin >> a >> b >> c;
	int sum = a + b + c;
	int pr = a * b * c;
	file << sum << " " << pr;
	file.close();
	readFile();
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
