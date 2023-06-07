#include <iostream>
#include <fstream>
struct Example {
    int data;
    char buff[8];
};
void fileInput(const int n, Example* file)
{
    for (int i = 0; i < n; ++i)
    {
        std::cin >> file[i].data;
        std::cin.ignore();
        std::cin.getline(file[i].buff, 8);
    }
}
void fileWrite(const int n, Example* file)
{
    std::ofstream binaryOutput("file.txt", std::ios::out|std::ios::binary|std::ios::app);

    for (int i = 0; i < n; ++i)
    {
        binaryOutput.write((char *)&file[i].data, sizeof(file[i].data));
        binaryOutput.write((char *)&file[i].buff, sizeof(file[i].buff));
    }
    binaryOutput.close();
}
int main()
{
    int n;
    std::cin >> n;
    Example* file = new Example[n];
    fileInput(n, file);
    fileWrite(n, file);
    delete[] file;
}