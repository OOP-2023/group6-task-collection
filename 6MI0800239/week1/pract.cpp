#include <iostream>
#include <fstream>
using namespace std;

void readFile(ifstream& ifs,int& sum,int& proiz)
{
    ifstream file("result.txt");

    if(!file.is_open())
    {
        return;
    }

    file >> sum >> proiz;
}

//int main()
//{
//    int a;
//    int b;
//    int c;
//
//    cin >> a >> b >> c;
//
//    int sum = a + b + c;
//    int proiz = a * b * c;
//
//    ofstream file("result.txt");
//
//    if (!file.is_open())
//    {
//        cout << "Error!" << endl;
//        return -1;
//    }
//
//    file << sum << proiz;
//
//    file.close();
//
//    std::ifstream in("result.txt");
//
//    readFile(in, sum, proiz);
//    cout << sum - proiz;
//
//    file.close();
//
//}



