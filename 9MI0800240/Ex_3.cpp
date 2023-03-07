// 28_02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstring>
#pragma warning (disable:4996)
using namespace std;

int numberLenght(int number)
{
	int count = 0;
	while (number != 0)
	{
		number /= 10;
		count++;
	}
	return count;
}
enum  Course { First = 1, Second, Third, Fourth, unknown };

struct Student
{
	char name[17]= "";
	int facNumber= -1;
	Course currentCourse = Course::unknown;
	double grade = -1.0;
};

std::istream& operator>>(std::istream& is, Course& course)
{
	int a;
	is >> a;
	course = static_cast<Course>(a);

	return is;
}
void read_student(Student& s)
{
	cout << "Name: ";
	cin.getline(s.name,17);
	cout << "Faculty number: ";
	cin >> s.facNumber;
	cout << "Current Course: ";
	cin >>s.currentCourse;
	cout << "Grade: ";
	cin >> s.grade;
}


void PrintCourse(const Course& course)
{
	switch (course)
	{
	case Course::First: cout << "First Course" << endl; break;
	case Course::Second: cout << "Second Course" << endl; break;
	case Course::Third: cout << "Third Course" << endl; break;
	case Course::Fourth: cout << "Fourth Course" << endl; break;
	default: cout << "Unknown" << endl;
	}
}

void print_student(const Student& s)
{
	cout << "Name: " << s.name << ", fn: " << s.facNumber << " ";
	PrintCourse(s.currentCourse);
	cout << "Grade: " << s.grade << endl;
}

bool initStudent(Student& toInit, char name[17], int facNumber, Course currentCourse, double grade)
{
	int nameLen = strlen(name);
	int facNemberLen = numberLenght(facNumber);
	if (nameLen > 17)
		return false;
	if (facNemberLen > 5)
		return false;
	if (grade < 3.00 && grade > 6.00)
		return false;

	return true;
}

void sorttable(int n, Student* a[],int number)
{
	for (int i = 0; i <= n - 2; i++)
	{
		int k = i;
		double max = average(a[i]->grade,number);
		for (int j = i + 1; j <= n - 1; j++)
			if (average(a[j]->grade, number) > max)
			{
				max = average(a[j]->grade, number);
				k = j;
			}
		Student* x;
		x = a[i]; a[i] = a[k]; a[k] = x;
	}
}

double average(double* a, int number)
{
	double s = 0;
	for (int j = 0; j < number; j++)
		s += a[j];

		return s / number;
}
void printScholars(Student* students, size_t length, double average)
{

}

int main()
{
	int number;
	cout << "How many students will you enter : ";
	cin >> number;

	Student* tableOfStudents = new Student[number];

	for (size_t i = 0; i < number; i++)
	{
		read_student(tableOfStudents[i]);
		bool initStudent(Student & toInit, char name[17], int facNumber, Course currentCourse, double grade);
	}

	for (size_t i = 0; i < number; i++)
	{
		print_student(tableOfStudents[i]);
		cout << endl;
	}


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
