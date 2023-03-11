// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
enum class Course
{
	first,
	second,
	third,
	fourth
};
void printCourse(const Course& st)
{
	switch (st)
	{
	case Course::first:cout << "first"; break;
	case Course::second:cout << "second"; break;
	case Course::third:cout << "third"; break;
	case Course::fourth:cout << "fourth"; break;
	}
}
struct Student
{
	double averageCourseMark;
	int fN;
	Course student;
	char name[17];
};
void printStudent(const Student& toPrint)
{
	cout << toPrint.averageCourseMark << toPrint.fN << toPrint.name;
	printCourse(toPrint.student);
}
bool initStudent(Student& toInit, char name[16], int facNumber, Course currentCourse, double grade)
{
	cin >> grade;
	cin >> facNumber;
	if (grade >= 3 && grade <= 6 && facNumber > 0)
	{
		int i = 0;
		int facNumberCopy = 0;
		while (facNumberCopy != 0)
		{
			facNumberCopy /= 10;
			i++;
		}
		if (i == 5)
		{
			cin.getline(toInit.name, 16);
			Course currentCourse = Course::first;
			return true;
		}
		return false;
	}
}
int main()
{

}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
