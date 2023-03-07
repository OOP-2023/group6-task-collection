#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream file ("MyFile.txt");

    if(!file.is_open())
    {
        cout << "Error!" << endl;
        return -1;
    }
    int count = 0;
    while(!file.eof())
    {
        char c = file.get();
        if(c!='a' && c!='d')
        {
            count ++;
        }
    }
    cout << count;
    file.close();
}
