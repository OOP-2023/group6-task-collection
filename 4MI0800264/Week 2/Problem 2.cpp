#include <iostream>
#include <fstream>
using namespace std;

int findCharsDifferentFromAandD()
{
	int count = 0;
	ifstream file("MyText.txt");

	if (!file.is_open())
	{
		cout << "Error!" << endl;
		return -1;
	}

	char currentChar;

	while (true)
	{
		file.get(currentChar);

		if (file.eof())
			break;

		count = (currentChar != 'a' && currentChar != 'd') ? count + 1 : count;
	}

	file.close();
	return count;

}

int main()
{
	ofstream file("MyText.txt");
	file << "asdasaaaaaaaaaaaaaaaaaaaaaaaaaas" << endl;
	file.close();

	cout << findCharsDifferentFromAandD() << endl;
	return 0;
}