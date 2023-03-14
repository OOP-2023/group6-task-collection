#include <iostream>
#include <fstream>
using namespace std;

void readNumbers(int& a, int& b, int& c)
{
	ofstream file("result.txt");

	if (!file.is_open())
	{
		cout << "Error!" << endl;
		return;
	}

	cin >> a >> b >> c;

	file << a + b + c << " " << a * b * c << endl;
	
	file.close();
}

int outputSubstraction()
{
	ifstream file("result.txt");

	if (!file.is_open())
	{
		cout << "Error!" << endl;
		return -1;
	}

	int sum, multiplication;
	file >> sum >> multiplication;
	
	file.close();
	return  (sum - multiplication);
}


int main()
{
	int a, b, c;
	readNumbers(a, b, c);

	cout << outputSubstraction();

	return 0;
}