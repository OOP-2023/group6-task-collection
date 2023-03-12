#include <iostream>
#include <fstream>
using namespace std;

const int BUFF_SIZE = 1024;
int main()
{
    int count = 0;
    ifstream file("myFile.txt");
    if (!file.is_open())
    {
        cout << "Error!" << endl;
        return -1;
    }
    while (!file.eof())
    {
        char c = file.get();
        if (c != 'a' && c != 'd' && c >= 0)
        {
            count++;
        }
    }
    cout << count;
    file.close();
}
