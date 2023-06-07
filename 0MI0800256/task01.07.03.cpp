#include <iostream>
#include <fstream>
using namespace std;

struct Numbers{
    int a;
    int b;
    int c;
};

int read()
{
ifstream file("result.txt");
int sum =0;
int mult = 0;
file >> sum >> mult;
file.close();
return mult-sum;
}
int main()
{
    ofstream file ("result.txt");

    if(!file.is_open())
    {
        cout << "Error!" << endl;
        return -1;
    }
    Numbers obj;
    file << obj.a*obj.b*obj.c << " " << obj.a + obj.b + obj.c;
    file.close();
}
