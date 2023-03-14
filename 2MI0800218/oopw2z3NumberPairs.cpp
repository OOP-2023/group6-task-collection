using namespace std;
#include <fstream>
#include <assert.h>
#include <iostream>

struct Pair {
	int x;
	int y;
};

Pair createPair(int x, int y) {
	return Pair { x, y };
}

void initPair(Pair& toInit, int x, int y) {
	toInit.x = x;
	toInit.y = y;
}

Pair readPairFromFile(std::ifstream& inFile) {
	if (!inFile.is_open())
		return createPair(0, 0);

	int x = inFile.get();
	int y = inFile.get();
	return createPair(x, y);
}

void writePairToFile(std::ofstream& outFile, const Pair& toWrite) {
	if (!outFile.is_open())
		return;
	outFile << toWrite.x << " " << toWrite.y << endl;
}

struct Relation {
	Pair pairsData[25];
	int pairsCount = 0;
};

bool addPair(Relation& rel, Pair& toInsert) {
	if (rel.pairsCount >= 25)
		return false;
	rel.pairsData[rel.pairsCount] = toInsert;
	rel.pairsCount++;
	return true;
}

bool writeRelation(Relation& rel, const char* filepath) {
	ofstream file(filepath);
	if (!file.is_open()) {
		return false;
	}

	for (size_t i = 0; i < rel.pairsCount; i++)
	{
		writePairToFile(file, rel.pairsData[i]);
	}
	file.flush();
	return true;
}

bool readRelation(Relation& rel, const char* filepath) {
	ifstream file(filepath);
	if (!file.is_open()) {
		return false;
	}

	rel.pairsCount = 0;
	while (true)
	{
		rel.pairsData[rel.pairsCount] = readPairFromFile(file);

		if (file.eof())
			break;

		rel.pairsCount++;
	}
}

int main()
{
	
}