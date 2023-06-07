#include <iostream>
#include <fstream>

using std::cin, std::cout,
    std::ofstream, std::ifstream;

struct Example {
    int data;
    char buff[8];
};

int main() {
    cout<<"Bitte schreiben Sie eine Nummer > 0 ein: ";
    int n;
    cin>>n;

    while(n<=0) {
        cout<<"Fehler! Bitte geben Sie eine andere Nummer, aber diesmal > 0 :";
        cin>>n;
    }

    ofstream our_file("zad1_file.txt", std::ios::binary | std::ios::app);

    if(!our_file.is_open()){
        cout<<"File konnte sich  nicht oefnen. Es ist irgendwie ein Fehler gewesen.";
        return -1;
    }

    Example* arr = new Example[n];

    for(int i=0; i<n; i++) {
        cout<<"Example "<<i+1<<":\ndata: ";
        cin >> arr[i].data;
        cin.ignore();
        cout<<"buff (<=7 characters): ";
        cin.getline(arr[i].buff, 8);
    }

    our_file.write((const char*)arr, n * sizeof(Example));

    our_file.close();
}
