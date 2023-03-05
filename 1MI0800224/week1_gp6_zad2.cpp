#include <iostream>
using namespace std;
unsigned int SIZE=100;

struct OrderedPair{
    int first;
    int second;
};

void PrintOrderedPair(const OrderedPair& PairToPrint){
    cout<<"("<<PairToPrint.first<<"; "<<PairToPrint.second<<")"<<endl;
}

bool isFirstBigger(const OrderedPair& FirstPair, const OrderedPair& SecondPair){
    if(FirstPair.first>SecondPair.first || (FirstPair.first==SecondPair.first && FirstPair.second>SecondPair.second))
        return true;
    return false;
}

OrderedPair findBiggestOne(OrderedPair* arr, size_t SIZE){
        int minIndex=0;
        OrderedPair minimal;
        for(int i=0; i<SIZE-1; i++){
            minIndex=i;
            minimal = arr[minIndex];
            for(int j=i+1; j<SIZE; j++){
                if(isFirstBigger(arr[j], minimal)){
                    minIndex=j;
                    minimal=arr[minIndex];
                }
            }
            arr[minIndex]=arr[i];
            arr[i]=minimal;
        }
        return arr[SIZE-1];
    }


int main(){
}
