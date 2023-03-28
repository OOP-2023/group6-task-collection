// 28_03.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>

struct Example {
    int data;
    char buff[8];
};

size_t examplesInFile(const char* filePath)
{
    std::ifstream file("filePath", std::ios::binary);
    size_t currpos = file.tellg();
    file.seekg(0, std::ios::end);
    size_t sizeOfFile = file.tellg();
    file.seekg(currpos);
    size_t countOfExample = sizeOfFile / sizeof(Example);

    return countOfExample;


}

Example checkPatternEqalsBuff(const char* filePath, const char* pattern)
{
    std::ifstream file("filePath", std::ios::binary);

}

void writeExample(Example& ex)
{
       std::cin >> ex.data;
       std::cin.ignore();
       std::cin.getline(ex.buff, 8);
}

int main()
{
    int n;
    std::cin >> n;

    std::ofstream file("MyFile.txt", std::ios::binary);
    Example* exArray = new Example[n];

    if (!file.is_open())
    {
        return -1;
    }

    for (size_t i = 0; i < n; i++)
    {
        writeExample(exArray[i]);
    }
    file.clear();


    file.write((const char*)exArray, n * sizeof(Example));
    file.close();
    delete[] exArray;
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
