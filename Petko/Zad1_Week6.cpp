// Zad1_Week6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;
struct Example {
    int data;
    char buff[8];
};
void initExample(Example& ex)
{
    cin >> ex.data;
    cin.getline(ex.buff, 8);
}
void initArrOfExample(int n,Example* ex)
{
    for (size_t i = 0; i < n; i++)
    {
        initExample(ex[i]);
    }
}
int main()
{
    unsigned n;
    cin >> n;
    char fileName[100];
    Example* arr = new Example[n];
    initArrOfExample(n, arr);
    cin.getline(fileName, 100);
    ofstream file(fileName,ios::binary|ios::app);
    if (!file.is_open()) {
        cout << "Error" << endl;
        delete[] arr;
        return -1;
    }
        file.write((char*)& arr,n* sizeof(Example));
    delete[]arr;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
