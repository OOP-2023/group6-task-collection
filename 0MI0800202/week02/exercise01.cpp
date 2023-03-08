//#include <iostream>
//#include <fstream>
//using namespace std;
//void printFromFile()
//{
//    ifstream file("result.txt");
//
//    if (!file.is_open())
//    {
//        cout << "Error!" << endl;
//        return;
//    }
//
//    int a, b;
//
//    file >> a >> b;
//    file.close();
//    cout << a - b;
//}
//int main()
//{
//    ofstream file("result.txt", ofstream::app);
//    if (!file.is_open())
//    {
//        cout << "Error!" << endl;
//        return -1;
//    }
//    int a, b, c;
//    cin >> a >> b >> c;
//    file << a + b + c << '\n' << a * b * c;
//
//    file.flush();
//    file.close();
//    printFromFile();
//}