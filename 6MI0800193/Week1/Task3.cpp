#include <iostream>
using namespace std;
enum class Year {
    first=1,
    second=2,
    third=3,
    fourth=4
};

struct Student
{
    char name[16];
    unsigned int fn;
    Year school_year;
    double grade;
};

void print_student(const Student& student)
{
    cout << student.name << " ";
    cout << student.fn << " ";
    switch (student.school_year)
    {
    case Year::first:
        cout << "first" << " ";
        break;
    case Year::second:
        cout << "second" << " ";
        break;
    case Year::third:
        cout << "third" << " ";
        break;
    case Year::fourth:
        cout << "fourth" << " ";
        break;
    }

    cout << student.grade << endl;
}

bool init_student(Student& toInit, char name[16], unsigned int facNumber, Year currentCourse, double grade)
{
    if (facNumber < 10000 || facNumber > 99999)
        return false;

    if ((int)currentCourse < 1 || (int)currentCourse > 4)
        return false;

    if (grade < 3 || grade > 6)
        return false;

    toInit.fn = facNumber;

    for (size_t i = 0; i < 16; i++)
    {
        toInit.name[i] = name[i];
    }

    toInit.school_year = currentCourse;
    toInit.grade = grade;
}

void print_scholars(const Student* students, size_t length, double average)
{
    for (size_t i = 0; i < length; i++)
    {
        if (students[i].grade > average)
            print_student(students[i]);
    }
}

void print_scholars_sorted(Student* students, size_t length, double average)
{
    int max_idx;
    for (size_t i = 0; i < length; i++)
    {   
        max_idx = i;
        for (size_t j = i+1; j < length; j++)
        {
            if (students[max_idx].grade < students[j].grade)
                max_idx = j;
        }
        if (max_idx != i)
            swap(students[max_idx], students[i]);
    }
    print_scholars(students, length, average);
}

int main()
{
    Student studs[4];
    char name[16] = "Test1";

    init_student(studs[0], name, 12345, Year::first, 4.50);
    init_student(studs[1], name, 12346, Year::second, 6.00);
    init_student(studs[2], name, 12347, Year::fourth, 3.30);
    init_student(studs[3], name, 12349, Year::third, 5.74);

    print_scholars(studs, 4, 3.00);
    cout << endl;
    print_scholars_sorted(studs, 4, 4);

}
