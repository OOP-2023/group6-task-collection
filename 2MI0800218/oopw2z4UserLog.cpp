using namespace std;
#include <fstream>
#include <assert.h>
#include <iostream>

union IpAdress {
    uint32_t adress;
    char octets[4];
};

struct Time {
    int hh;
    int mm;
    int ss;
};

struct Log {
    char name[16];
    IpAdress ip;
    Time time;
};

bool writeLog(const Log& toWrite, std::ofstream& outFile) {
    if (!outFile.is_open())
        return 0;
    outFile << toWrite.name << " " << toWrite.ip.adress << " " << 
        toWrite.time.hh << " " <<
        toWrite.time.mm << " " <<
        toWrite.time.ss << " " << endl;
    outFile.flush();
    return 1;
}

bool writeLogs(Log* logs, size_t length, const char* filePath) {
    ofstream outFile(filePath);
    for (size_t i = 0; i < length; i++)
    {
        if (!writeLog(logs[i], outFile))
            return 0;
    }
    return 1;
}

bool readLog(Log& toRead, std::ifstream& inFile) {
    if (!inFile.is_open())
        return 0;
    cin >> toRead.name >> toRead.ip.adress >> toRead.time.hh >> toRead.time.mm >> toRead.time.ss;
    return 1;
}

size_t logsCount(const char* filePath) {
    ifstream inFile(filePath);
    if (!inFile.is_open())
        return 0;

    size_t count = 0;
    char line[200];
    while (true)
    {
        char current = inFile.get();
        if (inFile.eof())
            break;
        if (current == '\n')
            count++;
    }
    inFile.clear();
    return count;
}

size_t readLogs(Log* logs, const char* filePath) {
    ifstream inFile(filePath);
    if (!inFile.is_open())
        return 0;

    size_t currentIndex = 0;
    while (true)
    {
        if (!readLog(logs[currentIndex], inFile))
            return 0;
        if (inFile.eof())
            break;
        currentIndex++;
    }
    inFile.clear();
    return currentIndex;
}

int main()
{

}