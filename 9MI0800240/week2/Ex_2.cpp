#include <iostream>
#include <fstream>
using namespace std;

int theNumberOfCharactersOtherThanAandD(ifstream& file, int count)
{
	count = 0;
	ifstream file("file.txt");
	if (!file.is_open())
	{
		return -1;
	}

	while (!file.eof())
	{
		char c = file.get();

		if (c!='a' && c!='d')
		{
			count++;
		}
	}

	file.close();
	return count;
}

int main()
{

}
