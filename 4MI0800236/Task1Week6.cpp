﻿// Task1Week6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>

struct Example {
    int data;
    char buff[8];
};

void readExample(Example& newExample) {
    std::cin >> newExample.data;
    std::cin.getline(newExample.buff, 8);
}


int main()
{
    int n;
    std::cin >> n;
    std::ofstream file("NewFile.txt", std::ios::binary);
    Example* exampleArr = new Example[8];

    if (!file.is_open()) {
        return -1;
    }

    for (int i = 0; i < n; i++){
        readExample(exampleArr[i]);
    }
    

    file.write((const char*)exampleArr, n * sizeof(Example));
    file.close();
    delete[] exampleArr;
      
}


