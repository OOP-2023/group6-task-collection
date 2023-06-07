#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

struct Example {
    int data;
    char buff[8];
};

void write2File(int n, const Example* arr, const char* filename) {
    std::ofstream file(filename, std::ios::app | std::ios::binary);
    if (!file.is_open()) {
        throw std::invalid_argument("file cannot be opened");
    }
    for (int i = 0;i < n;i++) {
        file.write((char*)&arr[i], sizeof(arr[i]));
    }
    file.close();
}

std::vector<Example> readFile(const char* filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        throw std::invalid_argument("file cannot be opened");
    }
    std::vector<Example> vec;
    while (!file.eof()) {
        Example temp;
        file.read((char*)&temp, sizeof(temp));
        vec.push_back(temp);
    }
    file.close();
    return vec;
}

void readStructs(int n) {
    Example* arr = new Example[n];
    for (int i = 0;i < n;i++) {
        std::cin >> arr[i].data >> arr[i].buff;
    }
    char filename[20];
    std::cin >> filename;
    write2File(n, arr, filename);
    delete[] arr;
}

void start() {
    int n;
    std::cin >> n;
    readStructs(n);
}

size_t examplesInFile(const char* filePath) {
    std::ifstream file(filePath, std::ios::binary);
    if (!file.is_open()) {
        throw std::invalid_argument("file cannot be opened");
    }
    file.seekg(0, file.end);
    size_t len = file.tellg();
    return len / sizeof(Example);
}

Example findExample(const char* filename, const char* pattern) {
    std::vector<Example> vec = readFile(filename);
    int size = vec.size();
    for (int i = 0;i < size;i++) {
        if (!strcmp(vec.at(i).buff, pattern)) {
            return vec.at(i);
        }
    }
    return Example{ -1,"err" };
}

int main() {
    //start();
    std::vector<Example> vec = readFile("file.bin");
    std::cout << vec.at(0).data << vec.at(0).buff << std::endl;
    std::cout << examplesInFile("file.bin") << std::endl;
    std::cout << findExample("file.bin", "lo1l").buff << std::endl;
}