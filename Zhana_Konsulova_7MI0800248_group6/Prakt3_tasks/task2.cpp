// 07.03.23 - prakt.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;

int CountSymbols(ifstream& file)
{
    if (!file.is_open())
    {
        cout << "Error!" << endl;
        return -1;
    }

    char ch;
    int count = 0;

    while (!file.eof())
    {
        ch = file.get();
        if(ch != 'a' && ch!= 'd')
            count++;
    }

    return count;

}
int main()
{
    ifstream file("task2.txt");

    cout << "count: " << CountSymbols(file);




}


