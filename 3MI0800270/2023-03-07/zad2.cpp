#include <fstream>
#include <iostream>
using namespace std;

int difChars(const char filename[]) {
    ifstream file(filename);
    int counter = 0;
    while (!file.eof()) {
        char ch = file.get();
        if (ch != 'a' || ch != 'd') {
            counter++;
        }
    }
    return counter;
}

int main() {
    cout << difChars("zad2.txt") << endl;
}