
#include <iostream>
#include <fstream>
#pragma warning (disable : 4996)

struct Example {
    int data;
    char buff[8];

    Example(int d, char* b) : data(d)
    {
        strcpy(buff, b);
    }
};

void WriteInFile(std::ofstream& outFile, int n)
{
    while (n--)
    {
        char buff[8];
        int data;
        std::cout << "Example structure: " << std::endl;
        std::cout << "data: ";
        std::cin >> data;
        std::cout << "text of 8 chars: ";
        std::cin.ignore();
        std::cin.getline(buff, 7);

        Example example(data, buff);
        outFile.write((char*)&example, sizeof(example));
    }
    outFile.close();
}
int main()
{
    std::cout << "Number: ";
    int n;
    std::cin >> n;

    std::ofstream outFileBinary("Example_astructures", std::ios::app, std::ios::binary);

    WriteInFile(outFileBinary, n);




}
