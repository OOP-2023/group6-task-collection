#include <iostream>
#include <fstream>
#include <stdexcept>
using namespace std;
struct Example
{
    int data;
    char buff[8];
};

size_t examples_in_file(const char* filePath)
{
    ifstream in_file(filePath, ios::binary);

    if (!in_file.is_open())
        throw std::exception("File wasnt open.");

    int count = 0;
    
    while (true)
    {
        Example temp;
        in_file.read((char*)&temp, sizeof(temp));

        if (in_file.eof())
            break;

        count++;
    }

    in_file.close();
    return count;
}

Example check_in_file(const char* filePath, const char* patern)
{
    ifstream in_file(filePath, ios::binary);

    if (!in_file.is_open())
        throw std::exception("File wasnt open.");

    while (true)
    {
        Example temp;
        in_file.read((char*)&temp, sizeof(temp));

        if (in_file.eof())
            break;
        
        if (strcmp(temp.buff, patern) == 0)
        {
            in_file.close();
            return temp;
        }
    }

    in_file.close();
    return {-1, "err"};
}


int main()
{
    cout << examples_in_file("new.dat") << endl;

    Example check1 = check_in_file("new.dat", "Ivan");
    cout << check1.data << " " << check1.buff << endl;

    Example check2 = check_in_file("new.dat", "Kris");
    cout << check2.data << " " << check2.buff << endl;
}
