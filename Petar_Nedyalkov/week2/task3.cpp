#include <iostream>
#include <fstream>

struct Pair {
	unsigned int x;
	unsigned int y;
};

Pair createPair(unsigned int first, unsigned int second)
{
	Pair newPair;
	newPair.x = first;
	newPair.y = second;

	return newPair;
}

void initPair(Pair& toInit, unsigned int x,unsigned int y)
{
	toInit.x = x;
	toInit.y = y;
}

Pair readPairFromFile(std::ifstream& inFile)
{
	Pair newPair;
	if (!inFile.is_open())
	{
		std::cout << "Error!" << std::endl;
		newPair.x = 0;
		newPair.y = 0;
	}
	else
	{
		unsigned int first, second;
		inFile >> first >> second;
		newPair.x = first;
		newPair.y = second;
	}
	inFile.close();
	return newPair;
}

void writePairToFile(std::ofstream& outFile, const Pair& toWrite)
{
	if (!outFile.is_open())
	{
		std::cout << "Error!" << std::endl;
		return;
	}

	outFile << toWrite.x <<" "<< toWrite.y;
	outFile.close();
}

struct Relation {
	Pair pairs[25];
	unsigned int count = 0;
};

bool addPair(Relation& arg, Pair& toInsert)
{
	if (arg.count == 25) 
		return false; //there is no space

	arg.pairs[arg.count].x = toInsert.x;
	arg.pairs[arg.count].y = toInsert.y;
	arg.count++; //after we add the last pair, the counter will be equal to 25

	return true;
}

bool writeRelation(const Relation& arg, std::ofstream file)
{
	if (arg.count == 0)
		return false; //Relation is empty

	if (!file.is_open())
	{
		std::cout << "Error!" << std::endl;
		return false;
	}
	unsigned int counter = arg.count - 1;

	while (counter != 0)
	{
		file << arg.pairs[counter].x << " " << arg.pairs[counter].y << std::endl;
		counter--;
	}

	file.close();
	return true;
}

bool readRelation(Relation& arg, std::ifstream file)
{
	if (!file.is_open())
	{
		std::cout << "Error!" << std::endl;
		return false;
	}
	
	while (!file.eof() || arg.count < 25)
	{
		file>> arg.pairs[arg.count].x >> arg.pairs[arg.count].y;
		arg.count++;
	}

	file.close();
	return true;
}


int main()
{
	Pair crPair;
	Pair newPair = createPair(5, 10);
	std::cout << newPair.x << " " << newPair.y << std::endl;

	initPair(crPair, 4, 6);
	std::cout << crPair.x << " " << crPair.y << std::endl;


	std::ofstream fileOut("Pairs.txt");
	if (!fileOut.is_open())
	{
		std::cout << "Error!" << std::endl;
		return -1;
	}
	writePairToFile(fileOut,crPair);

	std::ifstream fileIn("Pairs.txt");
	if (!fileIn.is_open())
	{
		std::cout << "Error!" << std::endl;
		return -1;
	}
	Pair readPair = readPairFromFile(fileIn);

	std::cout << readPair.x << " " << readPair.y << std::endl;

	fileIn.close();
	fileOut.close();
}