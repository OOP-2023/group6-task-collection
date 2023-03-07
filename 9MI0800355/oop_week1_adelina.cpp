#include <iostream>
using namespace std;

//ZAD 1
//struct transition {
//    int number;
//    char ch;
//};
//
//struct state{
//    int data[4];
//};
//
//struct stateInfo {
//
//};
//int main()
//{
//    stateInfo;
//}

//int main() {
//PairOfNumbers m;
//m.first = 2;
//m.second = 8;
//print(m);
//}


//zad 2
struct PairOfNumbers {
	int first;
	int second;
};
void print(const PairOfNumbers& arg) {
	cout << arg.first << " " << arg.second << " ";
}
void input(PairOfNumbers& obj1) {
	cin >> obj1.first >> obj1.second;
}

void compare(const PairOfNumbers& obj1, const PairOfNumbers& obj2) {
	if ((obj1.first > obj1.second) || (obj1.first == obj1.second && obj2.first > obj2.second)) {
		cout << "obj1 is bigger than obj2";
	}
	else if (obj1.second > obj1.first) {
		cout << "obj2 is bigger than obj1";
	}
}

int main() {
	PairOfNumbers obj1;
	PairOfNumbers obj2;
	input(obj1);
	input(obj2);
	compare(obj1, obj2);
}



//zad3
//struct Student {
//  char name[16];
//  int facNumber;
//  int course;
//  double grade;
//  void print(const Student& toPrint) {
//  cout << name << " " << facNumber << " " << course << " " << grade;
//  }
//};
//
//int main() {
//  Student myFirstStudent = { Simeon, 408800, 1, 5.2 };
//  myFirstStudent.print();
//  return 0;
//}
