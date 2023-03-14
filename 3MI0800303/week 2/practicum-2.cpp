#include <iostream>
#include <fstream>


void sumAndMult(const char* path, int times) {
    std::ofstream file(path);

    int sum = 0;
    int mult = 1;

    if (!file.is_open()) return; // handle error, maybe return -1

    for (size_t i = 0; i < times; i++)
    {
        int a;
        std::cin >> a;
        sum += a;
        mult *= a;
    }

    file << sum << std::endl << mult << std::endl;

    file.close();
}

int countDifferentChars(const char* path) {
    std::ifstream file(path);
    bool unique[4]{ 0 };
    int count = 0;
    while (!file.eof()) {
        int index = file.get() - 'a';
        if (index >= 3 || index <= 0) continue;
        if (!unique[index++]) count++;
    }

    file.close();
    return count;
}

struct Pair {
    int x;
    int y;
};

struct Relation {
    Pair pairs[25];
    size_t relations = 0;
};

Pair createPair(int x, int y) {
    return Pair{ x, y };
}

void initPair(Pair& toInit, const int x, const int y) {
    toInit = { x, y };
}

Pair readPairFromFile(std::ifstream& inFile) {
    return Pair{ inFile.get(), inFile.get() };
}

void writePairToFile(std::ofstream& outFile, const Pair& toWrite) {
    outFile << toWrite.x << " " << toWrite.y << std::endl;
}

bool addPair(Relation& arg, Pair& toInsert) {
    if (arg.relations > 25) return false;
    arg.pairs[arg.relations++] = toInsert;
    return true;
}

bool writeRelation(const Relation& arg, const char* filePath) {
    std::ofstream file(filePath);

    if (!file.is_open()) return false;

    for (size_t i = 0; i < arg.relations; i++)
    {
        if (arg.relations > 25) return false;
        writePairToFile(file, arg.pairs[i]);
    }

    file.close();
    return true;
}

bool readRelation(Relation& arg, const char* filepath) {
    std::ifstream file(filepath);

    if (!file.is_open()) return false;

    while (!file.eof()) {
        if (arg.relations > 25) return false;
        arg.pairs[arg.relations++] = readPairFromFile(file);
    }

    file.close();
    return true;
}

union IpV4 {
    uint32_t ip;
    char args[4];
};

union Time {
    uint32_t time;
    char args[3];
};

struct Log {
    char name[16];
    IpV4 ip;
    Time time;
};

bool writeLog(const Log& toWrite, std::ofstream& outFile) {
    if (!outFile.is_open()) return false;
    outFile << toWrite.name << " " << toWrite.ip.args << " " << toWrite.time.time; // for sure its better to log the ip & time by args.

    return true;
}

bool writeLogs(Log* logs, size_t size, const char* filePath) {
    std::ofstream file("log.txt");
    if (!file.is_open()) return false;


    for (size_t i = 0; i < size; i++)
    {
        writeLog(*(logs + i), file);
    }

    file.close();
    return true;
}

bool readLog(Log& toRead, std::ifstream& inFile) {
    if (!inFile.is_open()) return false;
    inFile >> toRead.name >> toRead.ip.ip >> toRead.time.time;
    return true;
}

size_t logsCount(const char* filePath){
    std::ifstream file(filePath);
    if (!file.is_open()) return 0;
    size_t count = 0;
    char buffer[1024];
    while (!file.eof()) {
        file.getline(buffer, 1024);
        count++;
    }
    return count;
}

int main()
{
    // sumAndMult("result.txt", 3); // 1
    //std::cout << countDifferentChars("file.txt"); // 2

    //3
    //Relation r;
    //Pair p = createPair(1, 2);
    //addPair(r, p);
    //writeRelation(r, "relation.txt");

    //4
    //IpV4 ip;
    //ip.args[0] = 1;
    //ip.args[1] = 0;
    //ip.args[2] = 0;
    //ip.args[3] = 127;

    //Time time;
    //time.args[0] = 3;
    //time.args[1] = 30;
    //time.args[2] = 30;

    //Log log{ "Something", ip, time };

    //std::ofstream file("log.txt");
    ////is opened check here

    //writeLog(log, file);
    //file.close();

}