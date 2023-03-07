#include <iostream>
#include <fstream>
#include <assert.h>
 
const int BUFF_SIZE = 1024;
void saveResultsInFile(int num1, int num2, const char location[BUFF_SIZE])
{
    std::ofstream file(location);
 
    if (!file.is_open())
        return;
 
    file << (num1 + num2) << std::endl << (num1 * num2);
}
int findDiffInFile(const char location[BUFF_SIZE])
{
    int num1, num2;
    std::ifstream file(location);
 
    if (!file.is_open())
        return -1;
 
    file >> num1 >> num2;
    return num1 - num2;
}
 
int sizeOfFile(const char location[BUFF_SIZE])
{
    int size = 0;
    std::ifstream file(location);
 
    if (!file.is_open())
        return -1;
 
    while (!file.eof())
    {
        char buffM[BUFF_SIZE];
        char* buff = buffM;
        file.getline(buffM, BUFF_SIZE);
        while (*buff)
        {
            if (*buff < 'a' || *buff > 'd') size++;
            buff++;
        }
    }
    file.close();
    return size;
}
 
struct pair
{
    int x, y;
};
pair createPair(int x, int y)
{
    pair p;
    p.x = x;
    p.y = y;
    return p;
}
void initPair(pair& toInit, int x, int y)
{
    toInit.x = x;
    toInit.y = y;
}
pair readPairFromFile(std::ifstream& inFile)
{
    return pair{ inFile.get(), inFile.get() };
}
void writePairToFile(std::ofstream& outFile, const pair& toWrite)
{
    outFile << toWrite.x << " " << toWrite.y;
}
struct relation
{
    pair pairs[25];
    size_t size = 0;
};
bool addPair(relation& arg, pair& toInsert)
{
    if (arg.size > 25) return false;
    arg.pairs[arg.size++] = toInsert;
    return true;
}
bool writeRelation(const relation& arg, const char* filePath)
{
    std::ofstream file(filePath);
    if (!file.is_open())
        return false;
    size_t currSize = arg.size;
    while (!file.eof())
    {
        if (currSize > 25) return false;
        writePairToFile(file, arg.pairs[currSize]);
        currSize++;
 
    }
}
bool readRelation(relation& arg, const char* filePath)
{
    std::ifstream file(filePath);
    if (!file.is_open())
        return false;
    size_t currSize = arg.size;
    while (!file.eof())
    {
        if (currSize > 25) return false;
        arg.pairs[currSize] = readPairFromFile(file);
        currSize++;
    }
}
union Ip
{
    uint32_t ip;
    char slots[4];
};
union Time
{
    uint32_t time; //last section is ms * 10
    char args[3];
};
struct Log
{
    char name[16];
    Ip ip;
    Time time;
};
bool writeLog(const Log& toWrite, std::ofstream& outFile)
{
    if (!outFile.is_open()) return false;
    outFile << toWrite.name << " " << toWrite.ip.ip << " " << toWrite.time.time;
    return true;
}
bool writeLogs(Log* logs, size_t size, const char* filePath)
{
    std::ofstream file(filePath);
    if (!file.is_open()) return false;
    for (size_t i = 0; i < size; i++)
    {
        writeLog(logs[i], file);
        file << std::endl;
    }
    return true;
}
 
int main()
{
    //int n1, n2;
    //std::cout << "Enter number1: ";
    //std::cin >> n1;
    //std::cout << "Enter number2: ";
    //std::cin >> n2;
    //saveResultsInFile(n1, n2);
 
    //std::cout << findDiffInFile();
 
    //std::cout << sizeOfFile();
 
 
}