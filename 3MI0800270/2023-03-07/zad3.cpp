#include <fstream>
#include <iostream>
using namespace std;

struct Pair {
    int a;
    int b;
};

struct Relation {
    Pair pairs[25];
    int count = 0;
};

Pair createPair(int x, int y) {
    return Pair{ x, y };
}

void initPair(Pair& toInit, int x, int y) {
    toInit = { x, y };
}

Pair readPairFromFile(std::ifstream& inFile) {
    int a, b;
    inFile >> a >> b;
    return Pair{ a, b };
}

void writePairToFile(std::ofstream& outFile, const Pair& toWrite) {
    outFile << toWrite.a << " " << toWrite.b;
}

bool addPair(Relation& arg, const Pair& toInsert) {
    if (arg.count >= 25) {
        cout << "Error";
        return 0;
    }

    arg.pairs[arg.count] = toInsert;
    arg.count++;
    return 1;
}

bool writeRelation(const Relation& arg, const char* filePath) {
    ofstream file(filePath);
    if (!file.is_open()) {
        cout << "Error";
        return 0;
    }
    for (int i = 0;i < arg.count;i++) {
        writePairToFile(file, arg.pairs[i]);
        if (i != arg.count - 1) {
            file << " ";
        }
    }
    file.close();
    return 1;
}

bool readRelation(Relation& arg, const char* filePath) {
    ifstream file(filePath);
    if (!file.is_open()) {
        cout << "Error";
        return 0;
    }

    while (!file.eof()) {
        int a, b;
        file >> a >> b;
        addPair(arg, createPair(a, b));
    }
    file.close();
    return 1;
}

int main() {
    Relation rel;
    addPair(rel, createPair(1, 2));
    addPair(rel, createPair(2, 2));
    addPair(rel, createPair(3, 2));
    writeRelation(rel, "zad3.txt");
    Relation rel2;
    readRelation(rel2, "zad3.txt");
}