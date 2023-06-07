#include <iostream>

#pragma warning (disable : 4996)

enum class Course {
	first, second, third, fourth
};

struct Student
{
	double averageGrade;
	int facultyNumber;
	Course c;
	char firstName[17];
};

void printStudent(const Student& toPrint)
{
	std::cout << toPrint.firstName << " " << toPrint.facultyNumber << " ";

	switch (toPrint.c)
	{
	case Course::first: std::cout << "first"; break;
	case Course::second: std::cout << "second"; break;
	case Course::third: std::cout << "third"; break;
	case Course::fourth: std::cout << "fourth"; break;
		default:break;
	};

	std::cout <<" " << toPrint.averageGrade << std::endl;
}

bool initStudent(Student& toInit, char name[17], int facNumber, Course currentCourse, double grade)
{
	if (grade - 3.0 < 0.0001 || grade - 6.0 > 0.00001) return false;
	else if (facNumber < 10000 || facNumber > 99999) return false;


	strcpy(toInit.firstName,name);
	toInit.facultyNumber = facNumber;
	toInit.c = currentCourse;
	toInit.averageGrade = grade;

	return true;

}

void sortScholars(Student* students, size_t size)
{
	for (size_t i = 0; i < size - 1; i++)
	{
		Student minScholar = students[i];
		int minIndex = i;

		for (size_t j = i; j < size; j++)
		{
			if (students[j].averageGrade < minScholar.averageGrade)
			{
				minScholar.averageGrade = students[j].averageGrade;
				minIndex = j;
			}
		}

		std::swap(students[minIndex],students[i]);
		std::swap(students[i], minScholar);
	}
}

void printScholars(Student* students, size_t size, double average)
{
	Student* studentsDyn = new Student();
	int count = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (students[i].averageGrade - average > 0.00001)
		{
			studentsDyn[count] = students[i];
			count++;
		}
	}

	sortScholars(studentsDyn, count);

	for (size_t i = 0; i < size; i++)
		printStudent(studentsDyn[i]);
}

int main()
{


}