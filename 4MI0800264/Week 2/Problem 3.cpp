#include <iostream>
#include <fstream>
using namespace std;

struct Pair
{
	int a, b;
};

struct Relation
{
	Pair pairArray[25];
	size_t size = 0;
};

Pair createPair(int x, int y)
{
	return { x,y };
}

void initPair(Pair& toInit, int x, int y)
{
	toInit.a = x;
	toInit.b = y;
}

Pair readPairFromFile(std::ifstream& inFile)
{
	Pair newPair;

	inFile >> newPair.a >> newPair.b;
	inFile.close();

	return newPair;
}

void writePairToFile(std::ofstream& outFile, Pair toWrite)
{
	outFile << toWrite.a << " " << toWrite.b << endl;
}

void addPair(Relation& arg,const Pair& toInsert)
{
	if (arg.size > 25)
		return;

	arg.pairArray[arg.size + 1] = toInsert;
	arg.size++;
}

bool writeRelation(const Relation& arg, const char* filePath)
{
	ofstream file(filePath);

	if (!file.is_open())
	{
		cout << "Error!" << endl;
		return false;
	}

	for (size_t i = 0; i < arg.size; i++)
	{
		file << arg.pairArray[i].a << " " << arg.pairArray[i].b << endl;
	}

	file.close();
	return true;
}

bool readRelation(Relation& arg, const char* filepath)
{
	ifstream file(filepath);

	if (arg.size > 25)
		return false;
	else if(!file.is_open())
	{
		cout << "Error, file not opened!" << endl;
		return false;
	}

	int currentPairA, currentPairB;

	while (true)
	{
		file >> currentPairA >> currentPairB;

		if (file.eof())
			break;

		addPair(arg, createPair(currentPairA,currentPairB));
	}

	return true;
}

int main()
{

	return 0;
}