#include <iostream>
#include <fstream>
//problem 1
void writeData() {
	std::ofstream file("result.txt");
	if (!file.is_open()) {
		std::cout << "Error!" << std::endl;
		return;
	}
	int a = 0, b = 0, c = 0;
	std::cin >> a >> b >> c;
	file << a + b + c << " " << a * b * c << std::endl;
	file.close();

}
void readData() {
	std::ifstream file("result.txt");
	if (!file.is_open()) {
		std::cout << "Error!" << std::endl;
		return;
	}
	int a = 0, b = 0;
	file >> a >> b;
	std::cout << a - b;
	file.close();
	}
//problem 2
int charCount() {
	std::ifstream file("myFile.txt");
	int count = 0;
	if (!file.is_open())
	{
		std::cout << "Error!" <<std::endl;
		return -1;
	}
	while (!file.eof()){
		char ch;
		file.get(ch);
		if (ch != 'a' && ch != 'd')count++;
	}
	file.close();
	return count;
}
//problem 3
struct Pair {
	unsigned x;
	unsigned y;
};
Pair createPair(unsigned x,unsigned y) {
	Pair pair;
	pair.x = x;
	pair.y = y;
}
void initPair(Pair& toInit, unsigned x, unsigned y) {
	toInit.x = x;
	toInit.y = y;
}
Pair readPairFromFile(std::ifstream& inFile) {
	Pair pair;
	inFile >> pair.x >> pair.y;
	inFile.close();
	return pair;
}
void writePairToFile(std::ofstream& outFile, const Pair& toWrite) {
	outFile << toWrite.x << " " << toWrite.y;
	outFile.close();
}
struct Relation {
	Pair pairArr[25];
	unsigned size = 0;
};
bool addPair(Relation& arg, Pair& toInsert){
	if (arg.size < 25) {
		arg.pairArr[arg.size++] = toInsert;
		return 1;
	}
	return 0;
}
bool writeRelation(const Relation& arg, const char* filePath) {
	std::ofstream file(filePath);
	for (size_t i = 0; i < arg.size; i++){
		file << arg.pairArr[i].x<<" "<< arg.pairArr[i].y;
	}
	file.close();
	return 1;
}
bool readRelation(Relation& arg, const char* filePath) {
	std::ifstream file(filePath);
	for (size_t i = 0; i < arg.size; i++){
		unsigned a = 0, b = 0;
		file >> a >> b;
		std::cout << a << " " << b << std::endl;
	}
}
int main(){
	
}

