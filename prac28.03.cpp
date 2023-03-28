#include <iostream>
#include<fstream>
using namespace std;

struct Example {
    int data;
    char buff[8];
};

void getExample(Example& exmp)
{
    cin >> exmp.data;
    cin.ignore();
    cin.getline(exmp.buff, 8, '\n');
}

bool isBuffEqPattern(ifstream& ifs, char* pattern,Example exmp)
{
    size_t currPos = ifs.tellg();
    ifs.seekg(0, ios::end);
    size_t n = ifs.tellg();
    ifs.seekg(currPos);
    int size = n / sizeof(Example);
    Example* arrExample = new Example[size];
    ifs.read((char*)arrExample, size * sizeof(Example));

    
}

size_t examplesInFile(const char* filePath)
{
    ifstream ifs("filePath.txt", ios::binary);
    size_t currPos = ifs.tellg();
    ifs.seekg(0, ios::end);
    size_t n = ifs.tellg();
    ifs.seekg(currPos);
    return n/sizeof(Example);
}

int main()
{
    int n;
    cin >> n;
    Example* strc = new Example[n];
    ofstream binFile("binaryFile.txt",ios::binary);
    if (!binFile.is_open())
    {
        cout << "The file can't be open";
    }

    for (size_t i = 0; i < n; i++)
        getExample(strc[i]);

    binFile.clear();

    binFile.write((const char*)strc, n * sizeof(Example));

    binFile.close();
    delete[] strc;  
}
