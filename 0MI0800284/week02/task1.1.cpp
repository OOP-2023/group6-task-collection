#include <iostream>
#include <fstream>
using namespace std;

struct Numbers
{
	int a, b, c;
};


int read()
{
	ifstream file("result.txt");

	int sum = 0;
	int mlt = 0;

	file >> mlt >> sum;
	int diff = sum - mlt;
	file.close();
	return diff;
}

int main()
{
	Numbers obj ={2, 6, 9};
	ofstream file("result.txt");
	if (!file.is_open())
	{
		cout << "Error!" << endl;
		return -1;
	}
	file << obj.a * obj.b * obj.c << " " << obj.a + obj.b + obj.c;
	file.close();
	read();
}
