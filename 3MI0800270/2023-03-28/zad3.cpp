#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

struct Offer {
    char name[25];
    size_t members;
    size_t holidays;
    size_t salary;
};

void write2File(int n, const Offer* arr, const char* filename) {
    std::ofstream file(filename, std::ios::app | std::ios::binary);
    if (!file.is_open()) {
        throw std::invalid_argument("file cannot be opened");
    }
    for (int i = 0;i < n;i++) {
        file.write((char*)&arr[i], sizeof(arr[i]));
    }
    file.close();
}

std::vector<Offer> readFile(const char* filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        throw std::invalid_argument("file cannot be opened");
    }
    std::vector<Offer> vec;
    while (!file.eof()) {
        Offer temp;
        file.read((char*)&temp, sizeof(temp));
        vec.push_back(temp);
    }
    file.close();
    return vec;
}

void readStructs(int n) {
    Offer* arr = new Offer[n];
    for (int i = 0;i < n;i++) {
        std::cin >> arr[i].name >> arr[i].members >> arr[i].holidays >> arr[i].salary;
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

void filterOffer(const char* filename, size_t minSalary) {
    std::vector<Offer> offers = readFile(filename);
    int size = offers.size();
    for (int i = 0;i < size;i++) {
        if (offers.at(i).salary >= minSalary) {
            std::cout << offers.at(i).name << ", Holiday Days: " << offers.at(i).holidays << ", Members: " << offers.at(i).members
                << ", Salary: " << offers.at(i).salary << std::endl;
        }
    }
}

Offer findOffer(const char* filename, const char* name) {
    std::vector<Offer> offers = readFile(filename);
    int size = offers.size();
    for (int i = 0;i < size;i++) {
        if (strcmp(offers.at(i).name, name)) {
            return offers.at(i);
        }
    }
}

