// Prakt_28.03.23.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#pragma warning (disable : 4996)

struct Example {
    int data;
    char buff[8];

    Example() : data(0), buff{""} {};
    Example(int d, const char* b) : data(d), buff{""}
    {
        if(strlen(b) < 8)
            strcpy(buff, b);
    }

    void print() const
    {
        std::cout << "data: " << data << std::endl;
        std::cout << buff << std::endl;
    }
};

size_t getFileSize(const char * filepath)  //!!!!
{
    std::ifstream fromFile(filepath, std::ios::out | std::ios::binary);

    fromFile.seekg(0, fromFile.end);
    size_t size = fromFile.tellg();

    fromFile.close();

    return size;
}
size_t examplesInFile(const char* filePath)
{
    std::cout << "File size: " << getFileSize(filePath) << std::endl;
   
    return getFileSize(filePath) / sizeof(Example);
}

int main()
{

    std::cout << examplesInFile("Example_structures");




}


