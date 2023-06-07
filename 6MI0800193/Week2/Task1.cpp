#include <iostream>
#include <fstream>
using namespace std;

void read_and_print(const char* filename)
{
	ifstream input_file(filename);

	int x, y;

	input_file >> x;
	input_file >> y;

	cout << x - y << endl;

	input_file.close();
}

int main()
{
	int a, b, c;
	cin >> a >> b >> c;

	ofstream output_file("result.txt");

	int sum = a + b + c;
	int mult = a * b * c;

	output_file << sum << endl;
	output_file << mult << endl;

	read_and_print("result.txt");

	output_file.close();
}
