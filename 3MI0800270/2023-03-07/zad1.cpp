#include <iostream>
#include <fstream>
using namespace std;

bool write2file(int a, int b, int c) {
    ofstream file("results.txt");
    if (!file.is_open()) {
        cout << "Error!" << endl;
        return -1;
    }
    file << a + b + c << " " << a * b * c;
    file.close();
}

bool readFromFile(const char filename[]) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error!" << endl;
        return -1;
    }
    int a, b;
    file >> a >> b;
    if (!file.eof()) {
        cout << "Error2!" << endl;
        return -1;
    }
    cout << a - b;
    file.close();
}

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    write2file(a, b, c);
    readFromFile("results.txt");
}