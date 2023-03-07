#include <iostream>
#include <fstream>
using namespace std;

void ReadFiles(ifstream& file)
{

    if (!file.is_open())
    {
        cout << "Error!" << endl;
        return;
    }
    int a, b;
    while (!file.eof())
    {
        file >> a >> b;
    }
    cout << a << " " << b << endl;
    cout << a - b;

    file.close();

}
int main()
{
    ofstream file("result.txt");
    ifstream file2("result.txt");

    if (!file.is_open())
    {
        cout << "Error!" << endl;
        return -1;
    }
    int a = 0, b = 0;
    cin >> a >> b;

    if (!file.eof())
    {
        file << "";
    }

    file << a + b << " " << a * b << endl;

    file.close();

    ReadFiles(file2);

}