#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct Invite{
    char name[25];
    int workers;
    int paidLeave;
    int salary;
};

void printInvite(const Invite& invite){
    cout << "name:" << invite.name << " workers: " << invite.workers << " Paid Leave: " << invite.paidLeave << " To be Paid: " << invite.salary << endl; 
}

void WriteNEntries(){
        int n;
        std::cin >> n;
        Invite* exp = new Invite[n];
        for (size_t i = 0; i < n; i++)
        {
            cin.getline(exp[i].name, 25);
            cin >> exp[i].workers >> exp[i].paidLeave >> exp[i].salary; 
        }

        std::ofstream of("invites.txt", std::ios::app | std::ios::binary);
        of.write((char *)exp, n*sizeof(Invite));
        delete[] exp;
}

void filterOffer(const char* filePath, size_t minSalary){
    std::ifstream invites(filePath, std::ios::binary);
    Invite buff;
    while(true){
        if(invites.eof()) break;
        invites.read((char *)&buff, sizeof(Invite));
        if(buff.salary >= minSalary) printInvite(buff);
    }
}

bool findOffer(const char* filePath, const char* name){
    std::ifstream invites(filePath, std::ios::binary);
    Invite buff;
    while(true){
        if(invites.eof()) break;
        invites.read((char *)&buff, sizeof(Invite));
        if(strcmp(buff.name, name) == 0) return true;
    }

    return false;
}


int main(){
    WriteNEntries();
}