#include <fstream>
#include <assert.h>
using namespace std;
#include <iostream>

int countNonAsAndNonDs(ifstream& input) {
	if (!input.is_open())
		return - 1;
	int count = 0;
	char c = input.get();
	while (true) {
		if (c != 'a' && c != 'd')
			count++;
		if (input.eof())
			break;
		c = input.get();
	}
}

int main()
{
	ifstream file("inp.txt");
	if (!file.is_open())
		return -1;
	cout << countNonAsAndNonDs(file);
}
