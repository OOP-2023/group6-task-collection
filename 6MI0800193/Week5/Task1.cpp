#include <iostream>
#include <fstream>
#include <stdexcept>
struct Example
{
    int data;
    char buff[8];
};

void input_struct(Example& ex)
{
    std::cin >> ex.data;
    std::cin.ignore();
    std::cin.getline(ex.buff, 8);
}

void input_structs(Example* structs, size_t count)
{
    for (size_t i = 0; i < count; i++)
    {
        input_struct(structs[i]);
    }
}

void write_struct(const Example& ex, std::ofstream& out)
{
    out.write((char*)&ex, sizeof(ex));
}

void write_data(const Example* structs, size_t count, std::ofstream& out)
{
    for (size_t i = 0; i < count; i++)
    {
        write_struct(structs[i], out);
    }
}

int main()
{
    int n;
    std::cin >> n;
    Example* examples = new Example[n];

    input_structs(examples, n);
    
    char file_name[100];
    std::cin.getline(file_name, 100);

    std::ofstream outfile(file_name, std::ios::binary | std::ios::app);

    if (!outfile.is_open())
    {
        delete[] examples;
        throw std::exception("File wasnt open.");
    }
    write_data(examples, n, outfile);

    outfile.close();
    delete[] examples;
    
}
/*
2
6 Test1
7 Test6
out.dat
*/