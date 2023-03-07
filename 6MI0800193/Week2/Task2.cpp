#include <iostream>
#include <fstream>
using namespace std;
size_t chars_in_file(const char* file)
{
    size_t chars = 0;
    ifstream input_file(file);

    while (true)
    {
        char c = input_file.get();

        if (input_file.eof()) break;

        if (c != 'a' && c != 'd' && c!= ' ' && c!='\n')
            chars++;
    }

    input_file.close();

    return chars;

}

int main()
{
    cout << chars_in_file("input.txt") << endl;
}
