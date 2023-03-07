#include <iostream>
#include <fstream>
using namespace std;

bool IsSymbolAorD(const char symbol){
    return (symbol=='a' || symbol == 'd');
}

int main(){
    int counter=0;
    ofstream file("file.txt");
    if(!file.is_open()){
        cout<<"Error";
        return -1;
    }

    int lenght;
    cin>>lenght;
    char* text = new char[lenght];
    for(int i=0; i<lenght-1; i++){
        cin.get(text[i]);
    }
    file<<text;

    file.close();
    delete [] text;

    ifstream file1("file.txt");
    if(!file1.is_open()){
        cout<<"Error";
        return -1;
    }
    while(!file1.eof()){
        if(!IsSymbolAorD(file1.get()))
        counter++;
    }
    file1.close();
    cout<<counter;
}
