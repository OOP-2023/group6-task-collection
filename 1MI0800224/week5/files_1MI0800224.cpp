#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ofstream our_file("file.txt");
    our_file<<3<<4;
    our_file.put('a');
    our_file.close();

    ifstream ifs("file.txt");
    while(true){
        if(ifs.eof())
            break;
        ifs.get();
    }
    ifs.clear();
    ifs.seekg(0, ios::beg);
    cout<<(int)(ifs.tellg());
    ifs.close();
}
