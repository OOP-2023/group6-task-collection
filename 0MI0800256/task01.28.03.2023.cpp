#include <iostream>
using namespace std;
#include <fstream>


struct Example {
    int data;
    char buff[8];
};


int readInt(const char* prompt) {
    int result;

    cout << prompt;
    cin >> result;
    cin.get(); // clean up the leftover \n from cin

    return result;
}

void readString(const char* prompt, char* buff, size_t buffSize) {
    cout << prompt;
    cin.getline(buff, buffSize);
}

Example readExample() {
    Example result;

    result.data = readInt("Enter data: ");
    readString("Enter buff: ", result.buff, 7);

    return result;
}


int main()
{
    int n = readInt("Enter n: ");
    Example* examples = new Example[n];

    for (int idx = 0; idx < n; idx++) {
        examples[idx] = readExample();
    }

    fstream file("task.01.txt", ios::in | ios::out | ios::trunc | ios::binary);
    if (!file.is_open()) {
        cout << "The file is not open!";
        return -1;
    }

    file.write((char*) examples, n * sizeof(Example));

    file.seekg(0, file.beg);
    file.read((char*)examples, n * sizeof(Example));
    if (file.gcount() < n * sizeof(Example)) {
        cout << "Read didn't go very well..." << endl;
        return -1;
    }
    file.close();

    delete[] examples;

    return 0;
}
