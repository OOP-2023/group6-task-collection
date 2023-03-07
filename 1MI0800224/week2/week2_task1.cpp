#include <iostream>
#include <fstream>
using namespace std;

double ReadFromFile(ifstream& file){
    if(!file.is_open())
        return -1;
    double sum, multiplication;
    file>>sum; file>>multiplication;
    return multiplication-sum;
}

int main(){
    double x, y, z;
    cin>>x>>y>>z;
    ofstream file("result.txt");
    if(!file.is_open()){
        cout<<"Error while opening file!";
        return -1;
    }
    file<<x+y+z<<endl;
    file<<x*y*z<<endl;
    file.close();
    ifstream file1("result.txt");
    cout<<ReadFromFile(file1);
    file1.close();
}
