#include <iostream>
using namespace std;

enum class Course{
    first =1,
    second =2,
    tirth = 3,
    forth=4
};

struct Student{
    double grade; // 8B
    unsigned int fn; // 4B
    char name[17]; // 2B*17=34B
    Course course;
};

void PrintStudent(const Student& toPrint){
    cout<<"name: "<<toPrint.name<<endl;
    cout<<"fn: "<<toPrint.fn<<endl;
    switch (toPrint.course){
        case Course::first: cout<<1; break;
        case Course::second: cout<<2; break;
        case Course::tirth: cout<<3; break;
        case Course::forth: cout<<4; break;
        default: cout<<"not a valid course";
    }
    //cout<<"course: "<<toPrint.course<<endl;
    cout<<"grade: "<<toPrint.grade<<endl;
}

int main(){
}
