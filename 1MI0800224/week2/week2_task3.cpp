#include <iostream>
#include <fstream>
struct pair{
    int x;
    int y;
};

pair createPair(int x, int y){
    pair newPair={x, y};
    return newPair;
}

void InitPair(pair& toInit, int x, int y){
    toInit={x, y};
}

pair ReadPairFromFile(std::ifstream& inFile){
    if(!inFile.is_open()){
        return {INT_MIN, INT_MAX};
    }
    int x, y;
    inFile>>x>>y;
    return {x, y};
    inFile.close();
}

void WritePairToFile(std::ofstream& outFile, const pair& toWrite){
    if(!outFile.is_open()){
        std::cout<<"Error";
    }
    else{
        outFile<<toWrite.x;
        outFile<<toWrite.y;
        outFile.close();
    }
}

int main(){

}
